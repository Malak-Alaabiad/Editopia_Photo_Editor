#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Image_Class.h"
#include <QMessageBox>
#include <QProgressBar>
#include<QThread>
#include<QString>
#include<QMainWindow>
#include <QPixmap>
#include <Windows.h>
#include <QFileDialog>
#include <QColorDialog>
#include <random>
#include <QDir>

using namespace std;

QString file_path;
Image image, copy_image, clear_image, image2;
bool isBright = false;
bool isBlur = false;
bool isFlip = false;
bool isRotate = false;
bool isSkew = false;
bool isOil = false;
bool isFrame = false;
bool isCrop = false;
bool isResize = false;
bool isMerge = false;
bool isMirror = false;
int Angle = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainFrame->hide();
    ui->brightWidget->hide();
    ui->FiltersGroup_2->hide();
    ui->FiltersGroup_3->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    ui->MirrorFrame->hide();
    ui->LoadingBar->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->mainFrame->show();
    ui->startFrame->hide();
}


void MainWindow::on_loadButton_clicked()
{
    try {
        file_path = QFileDialog::getOpenFileName(this, "Select image", QDir::homePath(), "Image Files (*.jpg *.tga *.png *.bmp)");
        QPixmap pix(file_path);
        image.loadNewImage(file_path.toStdString());
        clear_image = image;
        int w = ui->photo->width();
        int h = ui->photo->height();
        ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    } catch (...) {

    }
    ui->LoadingBar->show();
    ui->LoadingBar->setRange(70,100);
    for (int value = ui->LoadingBar->minimum(); value <= ui->LoadingBar->maximum(); value++){
        QThread::msleep(1);
        ui->LoadingBar->setValue(value);
        qApp->processEvents(QEventLoop::AllEvents);
        if (ui->LoadingBar->value()==100){
            ui->LoadingBar->hide();
        }
    }

}

void MainWindow::on_loadButton_2_clicked()
{
    try {
        file_path = QFileDialog::getOpenFileName(this, "Select image", QDir::homePath(), "Image Files (*.jpg *.tga *.png *.bmp)");
        QPixmap pix(file_path);
        image2.loadNewImage(file_path.toStdString());
        //int w = ui->photo->width();
        //int h = ui->photo->height();
        //ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    } catch (...) {

    }
}


void MainWindow::on_grayButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    ui->MirrorFrame->hide();

    Image Gray = image;
    for (int x = 0; x < Gray.width; ++x) {
        for (int y = 0; y < Gray.height; ++y) {
            unsigned int avg = 0;

            // Calculate the average value of RGB channels
            for (int z = 0; z < 3; ++z) {
                avg += Gray(x, y, z);
            }

            avg /= 3; // Calculate the average

            // Set all color channels to the average value to convert to grayscale
            Gray(x, y, 0) = avg;
            Gray(x, y, 1) = avg;
            Gray(x, y, 2) = avg;
        }
    }
    copy_image = Gray;
    QImage qImage(Gray.imageData, Gray.width, Gray.height, Gray.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}



void MainWindow::on_BaWButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    ui->MirrorFrame->hide();
    Image blackAwhite = image;
    for (int i = 0; i < blackAwhite.width; ++i) {
        for (int j = 0; j < blackAwhite.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += blackAwhite(i, j, k);
            }
            avg /= 3;
            unsigned int color = 127;
            if (avg <= color) {
                for (int k = 0; k < 3; ++k) {
                    blackAwhite(i, j, k) = 0;
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    blackAwhite(i, j, k) = 255;
                }
            }
        }
    }
    copy_image = blackAwhite;
    QImage qImage(blackAwhite.imageData, blackAwhite.width, blackAwhite.height, blackAwhite.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
     ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_invertButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    Image invert = image;
    for (int i = 0; i < invert.width; ++i) {
        for (int j = 0; j < invert.height; ++j) {
            // Invert each pixel's RGB values
            invert(i, j, 0) = 255 - invert(i, j, 0); // Invert red channel
            invert(i, j, 1) = 255 - invert(i, j, 1); // Invert green channel
            invert(i, j, 2) = 255 - invert(i, j, 2); // Invert blue channel
        }
    }
    copy_image = invert;
    QImage qImage(invert.imageData, invert.width, invert.height, invert.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}



void MainWindow::on_infraredButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    Image infrared = image;
    for (int i = 0; i < infrared.width; ++i) {
        for (int j = 0; j < infrared.height; ++j) {
            infrared(i, j, 0) = 255;
            infrared(i, j, 1) = 255 - infrared(i, j, 1);
            infrared(i, j, 2) = 255 - infrared(i, j, 2);
        }
    }
    copy_image = infrared;
    QImage qImage(infrared.imageData, infrared.width, infrared.height, infrared.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_purpleButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    Image purple = image;
    for (int i = 0; i < purple.width; ++i) {
        for (int j = 0; j < purple.height; ++j) {
            purple(i, j, 0) = fmin(255, purple(i, j, 0) + 10);
            purple(i, j, 1) = fmax(0, purple(i, j, 1) - 38);
            purple(i, j, 2) = fmin(255, purple(i, j, 2) + 10);
        }
    }
    copy_image = purple;
    QImage qImage(purple.imageData, purple.width, purple.height, purple.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_sunButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    Image Sunlight = image;
    for (int i = 0; i < Sunlight.width; ++i) {
        for (int j = 0; j < Sunlight.height; ++j) {

            Sunlight(i, j, 0) = fmin(255, Sunlight(i, j, 0) + 25);
            Sunlight(i, j, 1) = fmin(255, Sunlight(i, j, 1) + 25);
            Sunlight(i, j, 2) = fmax(0, Sunlight(i, j, 2) - 25);
        }
    }
    copy_image = Sunlight;
    QImage qImage(Sunlight.imageData, Sunlight.width, Sunlight.height, Sunlight.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_TVButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    Image TV = image;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-30, 30);
    int noiseIntensity = 100;

    for (int i = 0; i < TV.width; ++i) {
        for (int j = 0; j < TV.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int noise = int(dis(gen));
                TV(i, j, k) = max(0, min(255, TV(i, j, k) + noise));
            }
        }
    }

    for (int i = 0; i < TV.width; ++i) {
        for (int j = 0; j < TV.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                TV(i, j, k) = int(TV(i, j, k) / 10) * 10;
            }
        }
    }

    for (int j = 0; j < TV.height; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < TV.width; ++i) {
                for (int k = 0; k < 3; ++k) {
                    TV(i, j, k) = int(TV(i, j, k) * 0.8);
                }
            }
        }
    }
    copy_image = TV;
    QImage qImage(TV.imageData, TV.width, TV.height, TV.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_detectButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    bool isEdge = false;
    Image detect = image;
    for (int i = 0; i < detect.width; ++i) {
        for (int j = 0; j < detect.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += detect(i, j, k);
            }
            avg /= 3;
            unsigned int color = 127;
            if (avg <= color) {
                for (int k = 0; k < 3; ++k) {
                    detect(i, j, k) = 0;
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    detect(i, j, k) = 255;
                }
            }
        }
    }
    for (int i = 0; i < detect.width; ++i) {
        isEdge = false;
        for (int j = 0; j < detect.height; ++j) {
            if (detect(i, j, 0) == 0 && !isEdge){
                isEdge = true;
                continue;
            }else if (detect(i, j, 0) == 255 && isEdge){
                for (int k = 0; k < 3; ++k) {
                    detect(i, j, k) = 0;
                    isEdge = false;
                }
            }
            if (isEdge){
                for (int k = 0; k < 3; ++k) {
                    detect(i, j, k) = 255;
                }
            }
        }
    }
    copy_image = detect;
    QImage qImage(detect.imageData, detect.width, detect.height, detect.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_brightnessButton_2_clicked()
{
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isBright){
        isBright = false;
        ui->brightWidget->hide();
    }else{
        isBright = true;
        ui->brightWidget->show();
    }
}


void MainWindow::on_brightSlider_valueChanged(int value)
{
    Image bright = image;
    for (int i = 0; i < bright.width; ++i) {
        for (int j = 0; j < bright.height; ++j) {
            bright(i, j, 0) = min(int(bright(i, j, 0) * (value*0.25)), 255);
            bright(i, j, 1) = min(int(bright(i, j, 1) * (value*0.25)), 255);
            bright(i, j, 2) = min(int(bright(i, j, 2) * (value*0.25)), 255);
        }
    }
    copy_image = bright;
    QImage qImage(bright.imageData, bright.width, bright.height, bright.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_blurBtn_clicked()
{
    bool isBright = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isBlur){
        isBlur = false;
        ui->BlurWidget->hide();
    }else{
        isBlur = true;
        ui->BlurWidget->show();
    }
}

void MainWindow::on_BlurSlider_valueChanged(int value)
{
    Image blur = image;
    int radius = value;

    vector < vector <int> > BlurRed(blur.width, vector <int> (blur.height));
    vector < vector <int> > BlurGreen(blur.width, vector <int> (blur.height));
    vector < vector <int> > BlurBlue(blur.width, vector <int> (blur.height));

    for (int i = 0; i < blur.width; ++i) {
        for (int j = 0; j < blur.height; ++j) {
            int Red = 0, Green = 0, Blue = 0;
            for (int k = - radius; k <= radius; ++k) {
                int x = i + k;
                if (x >= 0 && x < blur.width) {
                    Red += blur(x, j, 0);
                    Green += blur(x, j, 1);
                    Blue += blur(x, j, 2);
                }
            }
            BlurRed[i][j] = Red;
            BlurGreen[i][j] = Green;
            BlurBlue[i][j] = Blue;
        }
    }

    for (int i = 0; i < blur.width; ++i) {
        for (int j = 0; j < blur.height; ++j) {
            int Red = 0, Green = 0, Blue = 0;
            for (int k = -radius; k <= radius; ++k) {
                int y = j + k;
                if (y >= 0 && y < blur.height) {
                    Red += BlurRed[i][y];
                    Green += BlurGreen[i][y];
                    Blue += BlurBlue[i][y];
                }
            }
            int avgRed = Red / ((2 * radius + 1) * (2 * radius + 1));
            int avgGreen = Green / ((2 * radius + 1) * (2 * radius + 1));
            int avgBlue = Blue / ((2 * radius + 1) * (2 * radius + 1));

            blur(i, j, 0) = avgRed;
            blur(i, j, 1) = avgGreen;
            blur(i, j, 2) = avgBlue;
        }
    }
    copy_image = blur;
    QImage qImage(blur.imageData, blur.width, blur.height, blur.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}

void MainWindow::on_pushButton_pressed()
{

    QImage qImage(image.imageData, image.width, image.height, image.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

}


void MainWindow::on_pushButton_released()
{
    QImage qImage(copy_image.imageData, copy_image.width, copy_image.height, copy_image.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_flipButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isFlip){
        isFlip = false;
        ui->FlipFrame->hide();
    }else{
        isFlip = true;
        ui->FlipFrame->show();
    }
}


void MainWindow::on_flipHButton_clicked()
{
    int Horizontal;
    Image flippedImage = image;
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            Horizontal = image.width - x;

            for (int z = 0; z < 3; z++) {
                flippedImage(x, y, z) = image(Horizontal, y, z);
            }
        }
    }
    copy_image = flippedImage;
    QImage qImage(flippedImage.imageData, flippedImage.width, flippedImage.height, flippedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_flipVButton_clicked()
{
    int Vertical;
    Image flippedImage = image;
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            Vertical = image.height - 1 - y;
            for (int z = 0; z < 3; z++) {
                flippedImage(x, y, z) = image(x, Vertical, z);
            }
        }
    }
    copy_image = flippedImage;
    QImage qImage(flippedImage.imageData, flippedImage.width, flippedImage.height, flippedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_FiltersButton_clicked()
{
    ui->FiltersGroup_2->show();
    ui->FiltersGroup_3->show();
    ui->FiltersButton->hide();
}


void MainWindow::on_FiltersButton_2_clicked()
{
    copy_image = clear_image;
    QImage qImage(clear_image.imageData, clear_image.width, clear_image.height, clear_image.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_rotateButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isRotate){
        isRotate = false;
        ui->RotateFrame->hide();
    }else{
        isRotate = true;
        ui->RotateFrame->show();
    }
}

void MainWindow::on_Rotate_clicked()
{
    if (Angle == 360){
        Angle = 0;
    }
    Angle += 90;
    Image rotate = image;
    int width, height;
    if (Angle == 90 || Angle == 270){
        width = rotate.height;
        height = rotate.width;
    } else{
        width = rotate.width;
        height = rotate.height;
    }

    Image rotatedImage(width, height);

    for (int i = 0; i < rotate.width; i++) {
        for (int j = 0; j < rotate.height; j++) {
            int new_i, new_j;
            if (Angle == 270) {
                new_i = j;
                new_j = height - 1 - i;
            } else if (Angle == 180) {
                new_i = width - 1 - i;
                new_j = height - 1 - j;
            } else if (Angle == 90) {
                new_i = width - 1 - j;
                new_j = i;
            } else if (Angle == 360){
                new_i = i;
                new_j = j;
            }
            for (int k = 0; k < 3; k++) {
                rotatedImage(new_i, new_j, k) = rotate(i, j, k);
            }
        }
    }
    copy_image = rotatedImage;
    QImage qImage(rotatedImage.imageData, rotatedImage.width, rotatedImage.height, rotatedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_exitButton_clicked()
{
    ui->startFrame->hide();
    exit(0);
}


void MainWindow::on_SkewButton_2_clicked()
{
    double skewDegree = ui->SkewSpin->value();
    Image skew = image;
    double radianDegree = abs(skewDegree) * M_PI / 180.0;
    double sine = sin(radianDegree);



    if(ui->LeftSkewButton->isChecked()){
        int width = skew.width + int(skew.height * abs(sine));
        int height = skew.height;
        Image skewedImage(width, height);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                double X = i + sine * (j - height);
                double Y = j;

                if (X >= 0 && X < skew.width && Y >= 0 && Y < skew.height) {
                    int x0 = floor(X);
                    int x1 = ceil(X);
                    int y0 = floor(Y);
                    int y1 = ceil(Y);

                    double deltaX = X - x0;
                    double deltaY = Y - y0;

                    for (int k = 0; k < 3; ++k) {
                        double channel = (1.0 - deltaX) * (1.0 - deltaY) * skew(x0, y0, k) +
                                         deltaX * (1.0 - deltaY) * skew(x1, y0, k) +
                                         (1.0 - deltaX) * deltaY * skew(x0, y1, k) +
                                         deltaX * deltaY * skew(x1, y1, k);
                        skewedImage(i, j, k) = channel;
                    }
                }
            }
        }
        copy_image = skewedImage;
        QImage qImage(skewedImage.imageData, skewedImage.width, skewedImage.height, skewedImage.width * 3, QImage::Format_RGB888);
        QPixmap img = QPixmap::fromImage(qImage);
        int w = ui->photo->width();
        int h = ui->photo->height();
        ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
    }else if(ui->RightSkewButton->isChecked()){
        int width = skew.width + int(skew.height * abs(sine));
        int height = skew.height;

        Image skewedImage(width, height);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                double X = i - sine * (j);
                double Y = j;

                if (X >= 0 && X < skew.width && Y >= 0 && Y < skew.height) {
                    int x0 = floor(X);
                    int x1 = ceil(X);
                    int y0 = floor(Y);
                    int y1 = ceil(Y);

                    double deltaX = X - x0;
                    double deltaY = Y - y0;

                    for (int k = 0; k < 3; ++k) {
                        double channel = (1.0 - deltaX) * (1.0 - deltaY) * skew(x0, y0, k) +
                                         deltaX * (1.0 - deltaY) * skew(x1, y0, k) +
                                         (1.0 - deltaX) * deltaY * skew(x0, y1, k) +
                                         deltaX * deltaY * skew(x1, y1, k);
                        skewedImage(i, j, k) = channel;
                    }
                }
            }
        }
        copy_image = skewedImage;
        QImage qImage(skewedImage.imageData, skewedImage.width, skewedImage.height, skewedImage.width * 3, QImage::Format_RGB888);
        QPixmap img = QPixmap::fromImage(qImage);
        int w = ui->photo->width();
        int h = ui->photo->height();
        ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

    }


}

void MainWindow::on_skewButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isSkew){
        isSkew = false;
        ui->SkewFrame->hide();
    }else{
        isSkew = true;
        ui->SkewFrame->show();
    }
}


void MainWindow::on_OilButton_3_clicked()
{
    Image Oil = image;
    int brushSize = ui->BruchSizeSlider->value();

    int width = image.width;
    int height = image.height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int intensityR[8] = {0};
            int intensityG[8] = {0};
            int intensityB[8] = {0};
            int count[8] = {0};

            for (int j = -brushSize; j <= brushSize; ++j) {
                for (int i = -brushSize; i <= brushSize; ++i) {
                    int newX = x + i;
                    int newY = y + j;
                    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                        int index = Oil(newX, newY, 0) * 8 / 256;
                        intensityR[index] += Oil(newX, newY, 0);
                        intensityG[index] += Oil(newX, newY, 1);
                        intensityB[index] += Oil(newX, newY, 2);
                        count[index]++;
                    }
                }
            }
            int maxCount = 0;
            int maxIndex = 0;
            for (int i = 0; i < 8; ++i) {
                if (count[i] > maxCount) {
                    maxCount = count[i];
                    maxIndex = i;
                }
            }
            Oil(x, y, 0) = intensityR[maxIndex] / count[maxIndex];
            Oil(x, y, 1) = intensityG[maxIndex] / count[maxIndex];
            Oil(x, y, 2) = intensityB[maxIndex] / count[maxIndex];
        }
    }
    copy_image = Oil;
    QImage qImage(Oil.imageData, Oil.width, Oil.height, Oil.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_oilButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isOil){
        isOil = false;
        ui->OilFrame->hide();
    }else{
        isOil = true;
        ui->OilFrame->show();
    }
}


void MainWindow::on_frameButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isFrame){
        isFrame = false;
        ui->Frameframe->hide();
    }else{
        isFrame = true;
        ui->Frameframe->show();
    }
}


void MainWindow::on_SimpleFrameButton_2_clicked()
{
    Image Frame = image;
    int width = Frame.width;
    int height = Frame.height;
    int frameWidth = width/30;

    QColor color = QColorDialog::getColor();
    for (int i = 0; i < width; ++i) {
        for (int y = 0; y < frameWidth; ++y) {
            Frame(i, y, 0) = color.red();
            Frame(i, y, 1) = color.green();
            Frame(i, y, 2) = color.blue();
            Frame(i, height - 1 - y, 0) = color.red();
            Frame(i, height - 1 - y, 1) = color.green();
            Frame(i, height - 1 - y, 2) = color.blue();
        }
    }

    for (int j = 0; j < height; ++j) {
        for (int y = 0; y < frameWidth; ++y) {
            Frame(y, j, 0) = color.red();
            Frame(y, j, 1) = color.green();
            Frame(y, j, 2) = color.blue();
            Frame(width - 1 - y, j, 0) =color.red();
            Frame(width - 1 - y, j, 1) = color.green();
            Frame(width - 1 - y, j, 2) = color.blue();
        }
    }
    copy_image = Frame;
    QImage qImage(Frame.imageData, Frame.width, Frame.height, Frame.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_FancyFrameButton_3_clicked()
{
    Image Frame = image;
    int width = Frame.width;
    int height = Frame.height;
    int frameWidth1 = height/50;
    int frameWidth2 = height/70;
    QColor color = QColorDialog::getColor();
    QColor color2 = QColorDialog::getColor();

    for (int i = frameWidth1; i < width-frameWidth1; ++i) {
        for (int y = frameWidth1; y < frameWidth1*2; ++y) {
            Frame(i, y+frameWidth1, 0) = color.red();
            Frame(i, y+frameWidth1, 1) = color.green();
            Frame(i, y+frameWidth1, 2) = color.blue();
        }
    }

    for (int i = frameWidth1; i < width-frameWidth1; ++i) {
        for (int y = frameWidth1; y < frameWidth1*2; ++y) {
            Frame(i, height - frameWidth1 - y, 0) = color.red();
            Frame(i, height - frameWidth1 - y, 1) = color.green();
            Frame(i, height - frameWidth1 - y, 2) = color.blue();
        }
    }

    for (int i = frameWidth1*3; i < width-frameWidth1*3; ++i) {
        for (int y = frameWidth2*5; y < frameWidth2*6; ++y) {
            Frame(i, y, 0) = color2.red();
            Frame(i, y, 1) = color2.green();
            Frame(i, y, 2) = color2.blue();
        }
    }

    for (int i = frameWidth1*3; i < width-frameWidth1*3; ++i) {
        for (int y = frameWidth2*5; y < frameWidth2*6; ++y) {
            Frame(i, height - y, 0) = color2.red();
            Frame(i, height - y, 1) = color2.green();
            Frame(i, height - y, 2) = color2.blue();
        }
    }

    for (int j = frameWidth1*4; j < height - frameWidth1*3.5; ++j) {
        for (int y = frameWidth1*3; y < frameWidth1*4; ++y) {
            Frame(y, j, 0) = color2.red();
            Frame(y, j, 1) = color2.green();
            Frame(y, j, 2) = color2.blue();
        }
    }

    for (int j = frameWidth1*2; j < height-frameWidth1*2; ++j) {
        for (int y = frameWidth1*3; y < frameWidth1*4; ++y) {
            Frame(width - y + frameWidth1*2, j, 0) = color.red();
            Frame(width - y + frameWidth1*2, j, 1) = color.green();
            Frame(width - y + frameWidth1*2, j, 2) = color.blue();
        }
    }

    for (int j = frameWidth1*2; j < height-frameWidth1*2; ++j) {
        for (int y = frameWidth1; y < frameWidth1*2; ++y) {
            Frame(y, j, 0) = color.red();
            Frame(y, j, 1) = color.green();
            Frame(y, j, 2) = color.blue();
        }
    }

    for (int j = frameWidth2*5; j < height-frameWidth2*5 + 1; ++j) {
        for (int y = frameWidth2 * 4; y < frameWidth2 * 5; ++y) {
            Frame(width - y, j, 0) = color2.red();
            Frame(width - y, j, 1) = color2.green();
            Frame(width - y, j, 2) = color2.blue();
        }
    }

    copy_image = Frame;
    QImage qImage(Frame.imageData, Frame.width, Frame.height, Frame.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_mergeButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    if(isMerge){
        isMerge = false;
        ui->Mergeframe->hide();
    }else{
        isMerge = true;
        ui->Mergeframe->show();
    }
}


void MainWindow::on_ResizeButton_2_clicked()
{
    int width = ui->WidthspinBox->value();
    int height = ui->HeightspinBox->value();
    Image resize(width, height);
    double ratioW, ratioH;
    ratioH = double (image.height)/height;
    ratioW = double (image.width)/width;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int x = round(i * ratioW);
            int y = round(j * ratioH);
            for (int k = 0; k < 3; ++k) {
                resize(i, j, k) = image(x, y, k);
            }
        }
    }
    copy_image = resize;
    QImage qImage(resize.imageData, resize.width, resize.height, resize.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w,h;
    if (width > ui->photo->width() || height > ui->photo->height()){
        w = ui->photo->width();
        h = ui->photo->height();
    }else{
        w = width;
        h = height;
    }
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_cropButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isCrop){
        isCrop = false;
        ui->Cropframe->hide();
    }else{
        isCrop = true;
        ui->Cropframe->show();
    }
}


void MainWindow::on_ResizeButton_3_clicked()
{
    //Image image2;
    int width = max(image.width, image2.width);
    int height = max(image.height, image2.height);
    Image resize(width, height);
    Image resize1(width, height);
    double ratioW, ratioH, ratioH1, ratioW1;
    ratioH = double (image.height)/height;
    ratioW = double (image.width)/width;
    ratioH1 = double (image2.height)/height;
    ratioW1 = double (image2.width)/width;
    Image mergedImage(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            // Resize the first image
            int x = round(i * ratioW);
            int y = round(j * ratioH);
            for (int k = 0; k < 3; ++k) {
                resize(i, j, k) = image(x, y, k);
            }
        }
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            // Resize the second image
            int x = round(i * ratioW1);
            int y = round(j * ratioH1);
            for (int k = 0; k < 3; ++k) {
                resize1(i, j, k) = image2(x, y, k);
            }
        }
    }
    // Merge images pixel by pixel
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Take the average of pixel values
                mergedImage(i, j, k) = (resize(i, j, k) + resize1(i, j, k)) / 2;
            }
        }
    }
    copy_image = mergedImage;
    QImage qImage(mergedImage.imageData, mergedImage.width, mergedImage.height, mergedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_commonareaButton_2_clicked()
{
    //Image image2; // Load the second image
    // Determine the dimensions of the merged image
    int width = min(image.width, image2.width);
    int height = min(image.height, image2.height);
    // Create the merged image with dimensions equal to the smaller of the two images
    Image mergedImage(width, height);
    // Merge images pixel by pixel
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                mergedImage(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2; // Take the average of pixel values
            }
        }
    }
    copy_image = mergedImage;
    QImage qImage(mergedImage.imageData, mergedImage.width, mergedImage.height, mergedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_CropButton_4_clicked()
{
    int x = ui->WCropSpin->value();
    int y = ui->HCropSpin->value();
    string directionX, directionY;
    int cropWidth = image.width - x;
    int cropHeight = image.height - y;
    Image croppedImage(cropWidth, cropHeight);
    if (x < 0 || y < 0 || x > image.width || y > image.height) {
        cout << "Invalid crop dimensions." << endl;
    } else {
        int row = 0, column = 0;
        for (int i = 0; i < cropWidth; ++i) {
            for (int j = 0; j < cropHeight; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (ui->cropTButton->isChecked()) {
                        column = y + j;
                    } else if (ui->cropBButton->isChecked()) {
                        column = j;
                    }
                    if (ui->cropLButton->isChecked()) {
                        row = x + i;
                    } else if (ui->cropRButton->isChecked()) {
                        row = i;
                    }
                    croppedImage(i, j, k) = image(row, column, k);
                }
            }
        }
    }
    copy_image = croppedImage;
    QImage qImage(croppedImage.imageData, croppedImage.width, croppedImage.height, croppedImage.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_resizeButton_2_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Mergeframe->hide();
    if(isResize){
        isResize = false;
        ui->Resizeframe->hide();
    }else{
        isResize = true;
        ui->Resizeframe->show();
    }
}


void MainWindow::on_FiltersButton_3_clicked()
{
    image = copy_image;
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();

}


void MainWindow::on_saveButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    try {
        QString filePath = QFileDialog::getSaveFileName(nullptr, "Save Image", "", "JPG Files (*.jpg);;TGA Files (*.tga);;PNG Files (*.png);;BMP Files (*.bmp)");
        image.saveImage(filePath.toStdString());
        QPixmap pix1;
        ui->photo->setText("Image");

    } catch (...) {
    }
}



void MainWindow::on_PopArtColorsButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isFlip = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->FlipFrame->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();

    // Load the input image
    Image popart = image;
    Image copy((popart.width)*2, (popart.height)*2);
    int width = popart.width;
    int height = popart.height;
    int m = 0;
    int l = 0;


    int reWidth, reHeight;
    reWidth = width/2;
    reHeight = height/2;
    Image resize(reWidth, reHeight);
    double ratioW, ratioH;
    ratioH = double (height)/reHeight;
    ratioW = double (width)/reWidth;

    for (int i = 0; i < reWidth; ++i) {
        for (int j = 0; j < reHeight; ++j) {
            int x = round(i * ratioW);
            int y = round(j * ratioH);

            for (int k = 0; k < 3; ++k) {
                resize(i, j, k) = popart(x, y, k);
            }
        }
    }

    for (int i = 0; i < resize.width; ++i) {
        for (int j = 0; j < resize.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                popart(i, j, k) = resize(m, j, k);
            }
            popart(i, j, 0) = min(255, popart(i, j, 0) + 90);
            popart(i, j, 1) = max(0, popart(i, j, 1) - 38);
            popart(i, j, 2) = min(0, popart(i, j, 2) + 90);
        }
        m += 1;
    }

    l = 0;
    m = 0;
    std::cout << l << std::endl;
    for (int i = 0; i < resize.width; ++i) {
        for (int j = resize.height; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                popart(i, j, k) = resize(m, j-reHeight, k);
            }
            popart(i, j, 0) = max(0, popart(i, j, 0) - 38);
            popart(i, j, 1) = min(255, popart(i, j, 1) + 90);
            popart(i, j, 2) = max(0, popart(i, j, 2) - 38);
        }
        m += 1;
    }
    m = 0;

    for (int i = reWidth; i < width; ++i) {
        for (int j = reHeight; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                popart(i, j, k) = resize(m, j - reHeight, k);
            }
            popart(i, j, 0) = max(0, popart(i, j, 0) - 40);
            popart(i, j, 1) = max(40, popart(i, j, 1) - 100);
            popart(i, j, 2) = min(255, popart(i, j, 2) +500);
        }
        m += 1;
    }
    m = 0;
    for (int i = reWidth; i < width; ++i) {
        for (int j = 0; j < reHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                popart(i, j, k) = resize(m, j, k);
            }
            popart(i, j, 0) = min(200, popart(i, j, 0) +40);
            popart(i, j, 1) = max(50, popart(i, j, 1) - 80);
            popart(i, j, 2) = min(200, popart(i, j, 2) + 200);
        }
        m += 1;
    }
    copy_image = popart;
    QImage qImage(popart.imageData, popart.width, popart.height, popart.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_mirrorButton_clicked()
{
    bool isBright = false;
    bool isBlur = false;
    bool isRotate = false;
    bool isSkew = false;
    bool isOil = false;
    bool isFrame = false;
    bool isCrop = false;
    bool isResize = false;
    bool isMerge = false;
    bool isMirror = false;
    int Angle = 0;
    ui->MirrorFrame->hide();
    ui->brightWidget->hide();
    ui->BlurWidget->hide();
    ui->RotateFrame->hide();
    ui->SkewFrame->hide();
    ui->OilFrame->hide();
    ui->Frameframe->hide();
    ui->Cropframe->hide();
    ui->Resizeframe->hide();
    ui->Mergeframe->hide();
    if(isMirror){
        isMirror = false;
        ui->MirrorFrame->hide();
    }else{
        isMirror = true;
        ui->MirrorFrame->show();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    Image mirror = image;
    int m = 0;
    for (int i = mirror.width/2; i < mirror.width; ++i) {
        for (int j = 0; j < mirror.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                mirror(i, j, k) = mirror(mirror.width/2 - m, j , k);
            }
        }
        m += 1;
    }
    copy_image = mirror;
    QImage qImage(mirror.imageData, mirror.width, mirror.height, mirror.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_2_clicked()
{
    Image Mirror = image;



    for (int i = 0; i < Mirror.width; ++i) {
        int m = 0;
        for (int j = Mirror.height/2; j < Mirror.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                Mirror(i, j, k) = Mirror( i, Mirror.height/2 - m, k);
            }
            m += 1;
        }

    }
    copy_image = Mirror;
    QImage qImage(Mirror.imageData, Mirror.width, Mirror.height, Mirror.width * 3, QImage::Format_RGB888);
    QPixmap img = QPixmap::fromImage(qImage);
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}


