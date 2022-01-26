/*
    Universidad de las Fuerzas Armadas - ESPE
    Proyecto - Segundo Parcial - Calculadora Polaca Inversa
    Autores:
    Paúl Mena
    Josué Merino
    Daniel Vizcarra
    Fecha de Creación: 15/01/2022
    Fecha de Modificación: 26/01/2022
*/

#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/core/core.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace cv;


class Image {
public:
    int showImage();
};

int Image::showImage() {

    Mat img;
    img = imread("C:\\Users\\JOSUE\\Downloads\\Telegram Desktop\\Polaca Inversa\\polacainversa1.png", IMREAD_COLOR);
    if (!img.data) {
        cout << "Error al encontrar el directorio" << endl;
        //        waitKey(0);
        //        getchar();
        return -1;
    }

    namedWindow("original", WINDOW_AUTOSIZE);
    imshow("original", img);
    waitKey(0);
    getchar();
    return 0;
}