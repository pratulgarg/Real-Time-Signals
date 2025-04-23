#include "real_time.h"
#include "ui_real_time.h"
#include <QMessageBox>
#include <QDebug>
#include <QSocketNotifier>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <vector>
#include <thread>

// Define real-time signals
#define SIGRT_START SIGRTMIN
#define SIG_COUNT 5

// Timer intervals (in milliseconds)
static const int INTERVALS[SIG_COUNT] = {100, 200, 300, 400, 500};

// Global variables for signal handling
static int signal_fd[2];
static std::vector<std::vector<int>> signal_threads(SIG_COUNT);
static int next_thread_id = SIG_COUNT + 1;

// Signal handler function
void signalHandler(int signo) {
    uint64_t sig = signo;
    write(signal_fd[1], &sig, sizeof(sig)); // Write signal to pipe
}

// ----------------------------------------------------------------------------
// Constructor
real_time::real_time(QWidget *parent)
    : QWidget(parent), ui(new Ui::real_time), current_signal_index(0) {
    ui->setupUi(this);

    // Initialize signal threads
    initializeThreads();

    // Create a pipe for signal handling
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, signal_fd) == -1) {
        qFatal("Failed to create signal socket pair");
    }

    // Set up signal handlers for real-time signals
    for (int i = 0; i < SIG_COUNT; ++i) {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = signalHandler;
        sigemptyset(&sa.sa_mask);
        if (sigaction(SIGRT_START + i, &sa, nullptr) == -1) {
            qFatal("Failed to set signal handler");
        }
    }

    // QSocketNotifier to listen for signal notifications
    notifier = new QSocketNotifier(signal_fd[0], QSocketNotifier::Read, this);
    connect(notifier, &QSocketNotifier::activated, this, &real_time::handleSignal);

    // Timer setup
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &real_time::sendSignal);
}

// ----------------------------------------------------------------------------
// Destructor
real_time::~real_time() {
    delete ui;
}

// ----------------------------------------------------------------------------
// Start/Stop button
void real_time::on_pushButton_start_clicked() {
    if (!timer->isActive()) {
        timer->start(INTERVALS[current_signal_index]);
        ui->pushButton_start->setText("Stop");
    } else {
        timer->stop();
        ui->pushButton_start->setText("Start");
    }
}

// ----------------------------------------------------------------------------
// Pause/Resume button
void real_time::on_pushButton_pause_clicked() {
    if (timer->isActive()) {
        timer->stop();
        ui->pushButton_pause->setText("Resume");
    } else {
        timer->start(INTERVALS[current_signal_index]);
        ui->pushButton_pause->setText("Pause");
    }
}

// ----------------------------------------------------------------------------
// Clear button
void real_time::on_pushButton_clear_clicked() {
    ui->textEdit->clear();
    ui->plainTextEdit->clear();

    // Reset thread tracking
    signal_threads.clear();
    signal_threads.resize(SIG_COUNT);
    next_thread_id = SIG_COUNT + 1;
    initializeThreads();
}

// ----------------------------------------------------------------------------
// Add threads button
void real_time::on_pushButton_add_clicked() {
    bool ok;
    int n = ui->lineEdit->text().toInt(&ok);
    if (ok && n > 0) {
        distributeThreads(n);
    } else {
        QMessageBox::warning(this, "Invalid Input", "Enter a valid number of threads.");
    }
}

// ----------------------------------------------------------------------------
// Initialize default threads (one thread per signal)
void real_time::initializeThreads() {
    for (int i = 0; i < SIG_COUNT; ++i) {
        signal_threads[i].push_back(i + 1);
    }
    updateThreadDistribution();
}

// ----------------------------------------------------------------------------
// Distribute new threads across signals
void real_time::distributeThreads(int n) {
    for (int i = 0; i < n; ++i) {
        signal_threads[i % SIG_COUNT].push_back(next_thread_id++);
    }
    updateThreadDistribution();
}

// ----------------------------------------------------------------------------
// Update thread distribution UI
void real_time::updateThreadDistribution() {
    QString distributionText = "Updated thread distribution:\n";
    for (int i = 0; i < SIG_COUNT; ++i) {
        distributionText += QString("Signal %1 -> Threads: ").arg(i + 1);
        for (int thread_id : signal_threads[i]) {
            distributionText += QString::number(thread_id) + " ";
        }
        distributionText += "\n";
    }
    ui->plainTextEdit->setPlainText(distributionText);
}

// ----------------------------------------------------------------------------
// Send a real-time signal to trigger thread execution
void real_time::sendSignal() {
    kill(getpid(), SIGRT_START + current_signal_index);
    current_signal_index = (current_signal_index + 1) % SIG_COUNT;
    timer->start(INTERVALS[current_signal_index]);
}

// ----------------------------------------------------------------------------
// Handle incoming signals from QSocketNotifier
void real_time::handleSignal() {
    uint64_t signo;
    read(signal_fd[0], &signo, sizeof(signo)); // Read signal number

    int signal_index = signo - SIGRT_START;
    if (signal_index >= 0 && signal_index < SIG_COUNT) {
        executeThreads(signal_index);
    }
}

// ----------------------------------------------------------------------------
// Execute assigned threads for a given signal
void real_time::executeThreads(int signal_index) {
    if (!signal_threads[signal_index].empty()) {
        for (int thread_id : signal_threads[signal_index]) {
            std::thread(&real_time::threadFunction, this, signal_index + 1, thread_id).detach();
        }
    }
}

// ----------------------------------------------------------------------------
// Thread function to log execution
void real_time::threadFunction(int signal_id, int thread_id) {
    QString message = QString("Received: Signal %1 -> Thread %2 executed")
                          .arg(signal_id)
                          .arg(thread_id);
    QMetaObject::invokeMethod(this, [this, message]() {
        ui->textEdit->append(message);
    }, Qt::QueuedConnection);
}
