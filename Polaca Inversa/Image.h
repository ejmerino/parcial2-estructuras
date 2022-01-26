#pragma once
/*
    Universidad de las Fuerzas Armadas - ESPE
    Proyecto - Segundo Parcial - Calculadora Polaca Inversa
    Autores:
    Paúl Mena
    Josué Merino
    Daniel Vizcarra
    Fecha de Creación: 15/01/2022
    Fecha de Modificación: 17/01/2022
*/

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
    img = imread("C:\\Users\\theda\\OneDrive\\Escritorio\\Finale\\Polaca Inversa\\polacainversa1.png", IMREAD_COLOR);
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