#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_loadButton_clicked();

    void on_grayButton_clicked();


    void on_BaWButton_clicked();

    void on_invertButton_2_clicked();

    void on_infraredButton_clicked();

    void on_purpleButton_clicked();

    void on_sunButton_clicked();

    void on_TVButton_clicked();

    void on_detectButton_clicked();

    void on_brightnessButton_2_clicked();

    void on_brightSlider_valueChanged(int value);

    void on_BlurSlider_valueChanged(int value);

    void on_blurBtn_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_flipButton_2_clicked();

    void on_flipHButton_clicked();

    void on_flipVButton_clicked();

    void on_FiltersButton_clicked();

    void on_FiltersButton_2_clicked();

    void on_rotateButton_2_clicked();

    void on_Rotate_clicked();

    void on_exitButton_clicked();

    void on_skewButton_2_clicked();

    void on_OilButton_3_clicked();

    void on_SkewButton_2_clicked();

    void on_oilButton_2_clicked();

    void on_frameButton_2_clicked();

    void on_SimpleFrameButton_2_clicked();

    void on_FancyFrameButton_3_clicked();

    void on_mergeButton_clicked();

    void on_ResizeButton_2_clicked();

    void on_cropButton_2_clicked();

    void on_ResizeButton_3_clicked();

    void on_commonareaButton_2_clicked();

    void on_CropButton_4_clicked();

    void on_resizeButton_2_clicked();

    void on_FiltersButton_3_clicked();

    void on_saveButton_clicked();

    void on_PopArtColorsButton_clicked();


    void on_mirrorButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_loadButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
