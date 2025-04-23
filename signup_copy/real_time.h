#ifndef REAL_TIME_H
#define REAL_TIME_H

#include <QWidget>
#include <QTimer>
#include <QSocketNotifier>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class real_time;
}
QT_END_NAMESPACE

class real_time : public QWidget {
    Q_OBJECT

public:
    explicit real_time(QWidget *parent = nullptr);
    ~real_time();

private slots:
    void on_pushButton_start_clicked();  // Start/Stop execution
    void on_pushButton_pause_clicked();  // Pause/Resume execution
    void on_pushButton_clear_clicked();  // Clear logs and reset execution
    void on_pushButton_add_clicked();    // Add additional threads
    void sendSignal();                   // Send real-time signal
    void handleSignal();                 // Handle incoming real-time signal
    void updateThreadDistribution();     // Update thread distribution UI

private:
    Ui::real_time *ui;
    QTimer *timer;                        // Timer for signal execution
    QSocketNotifier *notifier;            // Notifier for real-time signals
    int current_signal_index;             // Tracks the current signal index

    void initializeThreads();             // Initialize default thread distribution
    void distributeThreads(int n);        // Distribute additional threads dynamically
    void executeThreads(int signal_index); // Execute threads for a given signal
    void threadFunction(int signal_id, int thread_id); // Thread execution function
};

#endif // REAL_TIME_H
