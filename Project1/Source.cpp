#include<QtWidgets>
class MainWindow :public QMainWindow {
public:
	MainWindow();
	void onStartClick();
	void onStopClick();
private:
	QLabel* textLabel;
	QPushButton* startButton;
	QPushButton* stopButton;
};
MainWindow::MainWindow() {
	setFixedSize(900, 500);
	setWindowTitle("Test QPushButton v0.1");
	textLabel = new QLabel("testQLabel", this);
	textLabel->setGeometry(50, 100, 120, 30);
	textLabel->setFont(QFont("Courier", 12, QFont::Bold));
	QFont buttonFont("Rimes", 18, QFont::Normal);
	startButton = new QPushButton("Start", this);
	startButton->setGeometry(50, 150, 70, 50);
	startButton->setFont(buttonFont);
	stopButton = new QPushButton("Stop", this);
	stopButton->setGeometry(140, 150, 70, 50);
	stopButton->setFont(buttonFont);
	connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartClick);
	connect(stopButton, &QPushButton::clicked, this, &MainWindow::onStopClick);
}

void MainWindow::onStartClick() {
	textLabel->setText("start");
}
void MainWindow::onStopClick() {
	textLabel->setText("Stop");
}
int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow MainWin;
	MainWin.show();
	return app.exec();
}
