#include<iostream>
#include<fstream>
#include<map>
using namespace std;

class Cube {
private:
	char white[9];
	char red[9];
	char orange[9];
	char blue[9];
	char green[9];
	char yellow[9];

	void readSideFromKeyboard(char* side) {
		for (int i = 0; i < 9; i++) {
			cin >> side[i];
		}
	}
	void readSideFromFile(char* side, ifstream& fi) {
		for (int i = 0; i < 9; i++) {
			fi >> side[i];
		}
	}
	void displaySide(char face[9])
	{
		for (int i = 0; i < 9; i++)
		{
			cout << face[i] << " ";
		}
		cout << endl << endl;
	}

    /*--------------Шаги для сборки кубика рубика-----------------*/
    void swap(char& a, char& b)
    {
        char t = a;
        a = b;
        b = t;
    }
    void rotateByClock(char side)
    {
        switch (side) {
        case('w'): {
            cout << "Белая" << endl;
            swap(white[7], white[3]);
            swap(white[6], white[4]);
            swap(white[0], white[2]);
            swap(white[7], white[5]);
            swap(white[0], white[4]);
            swap(white[1], white[3]);

            swap(blue[0], orange[0]);
            swap(blue[7], orange[7]);
            swap(blue[6], orange[6]);
            swap(orange[6], green[6]);
            swap(orange[7], green[7]);
            swap(orange[0], green[0]);
            swap(green[6], red[6]);
            swap(green[7], red[7]);
            swap(green[0], red[0]);

            break;
        }
        case('r'): {
            cout << "Красная" << endl;
            swap(red[0], red[4]);
            swap(red[7], red[5]);
            swap(red[1], red[3]);
            swap(red[0], red[6]);
            swap(red[1], red[5]);
            swap(red[2], red[4]);

            swap(blue[6], white[3]);
            swap(blue[5], white[2]);
            swap(blue[4], white[1]);
            swap(white[1], green[0]);
            swap(white[2], green[1]);
            swap(white[3], green[2]);
            swap(green[0], yellow[3]);
            swap(green[1], yellow[2]);
            swap(green[2], yellow[1]);

            break;
        }
        case('y'): {
            cout << "Желтая" << endl;
            swap(yellow[1], yellow[5]);
            swap(yellow[2], yellow[4]);
            swap(yellow[0], yellow[6]);
            swap(yellow[1], yellow[3]);
            swap(yellow[0], yellow[4]);
            swap(yellow[7], yellow[5]);

            swap(blue[4], red[4]);
            swap(blue[3], red[3]);
            swap(blue[2], red[2]);
            swap(red[2], green[2]);
            swap(red[3], green[3]);
            swap(red[4], green[4]);
            swap(green[4], orange[4]);
            swap(green[3], orange[3]);
            swap(green[2], orange[2]);

            break;
        }
        case('o'): {
            cout << "Ораньжевая" << endl;
            swap(orange[4], orange[0]);
            swap(orange[3], orange[1]);
            swap(orange[5], orange[7]);
            swap(orange[4], orange[2]);
            swap(orange[5], orange[1]);
            swap(orange[6], orange[0]);

            swap(blue[2], yellow[5]);
            swap(blue[1], yellow[6]);
            swap(blue[0], yellow[7]);
            swap(yellow[5], green[6]);
            swap(yellow[6], green[5]);
            swap(yellow[7], green[4]);
            swap(green[6], white[7]);
            swap(green[5], white[6]);
            swap(green[4], white[5]);

            break;
        }
        case('g'): {
            cout << "Зеленая" << endl;
            swap(green[6], green[2]);
            swap(green[5], green[3]);
            swap(green[7], green[1]);
            swap(green[4], green[6]);
            swap(green[7], green[3]);
            swap(green[0], green[2]);

            swap(white[5], orange[2]);
            swap(white[4], orange[1]);
            swap(white[3], orange[0]);
            swap(yellow[3], orange[2]);
            swap(yellow[4], orange[1]);
            swap(yellow[5], orange[0]);
            swap(yellow[3], red[6]);
            swap(yellow[4], red[5]);
            swap(yellow[5], red[4]);

            break;
        }
        case('b'): {
            cout << "Синяя" << endl;
            swap(blue[1], blue[7]);
            swap(blue[2], blue[6]);
            swap(blue[5], blue[3]);
            swap(blue[2], blue[0]);
            swap(blue[7], blue[3]);
            swap(blue[6], blue[4]);

            swap(yellow[1], orange[4]);
            swap(yellow[0], orange[5]);
            swap(yellow[7], orange[6]);
            swap(white[7], orange[4]);
            swap(white[0], orange[5]);
            swap(white[1], orange[6]);
            swap(white[7], red[0]);
            swap(white[0], red[1]);
            swap(white[1], red[2]);

            break;
        }
        }
    }

    // Алгоритмы для сбокри 1-го слоя ( белая часть, ее углы )
    void whiteBottom(char q)
    {
        if ((yellow[0] == 'w' && blue[3] == q) || (yellow[2] == 'w' && red[3] == q) || (yellow[4] == 'w' && green[3] == q) || (yellow[6] == 'w' && orange[3] == q))
        {
            if (q == 'b')
            {
                while (blue[3] != q || yellow[0] != 'w')
                {
                    rotateByClock('y');
                }
            }
            if (q == 'r')
            {
                while (red[3] != q || yellow[2] != 'w')
                {
                    rotateByClock('y');
                }
                if (q != 'b')
                {
                    while (white[0] != 'w' && blue[7] != 'b')
                    {
                        rotateByClock('w');
                    }
                }
            }
            if (q == 'g')
            {
                while (green[3] != q || yellow[4] != 'w')
                {
                    rotateByClock('y');
                }
                if (q != 'b')
                {
                    while (white[0] != 'w' && blue[7] != 'b')
                    {
                        rotateByClock('w');
                    }
                }
            }
            if (q == 'o')
            {
                while (orange[3] != q || yellow[6] != 'w')
                {
                    rotateByClock('y');
                }
                if (q != 'b')
                {
                    while (white[0] != 'w' && blue[7] != 'b')
                    {
                        rotateByClock('w');
                    }
                }
            }
            rotateByClock(q); rotateByClock(q);
        }
    }
    void rightAlgorithm(char a, char c)
    {
        rotateByClock(a);
        rotateByClock(a); 
        rotateByClock(a);
        rotateByClock('y');
        rotateByClock(a); 
        rotateByClock(c);
    }
    void whiteRightAlg(char q)
    {
        if (blue[1] == 'w' || red[1] == 'w' || green[1] == 'w' || orange[1] == 'w')
        {
            if (blue[5] == q && red[1] == 'w')
            {
                rightAlgorithm('b', q);
            }
            if (red[5] == q && green[1] == 'w')
            {
                rightAlgorithm('r', q);
            }
            if (green[5] == q && orange[1] == 'w')
            {
                rightAlgorithm('g', q);
            }
            if (orange[5] == q && blue[1] == 'w')
            {
                rightAlgorithm('o', q);
            }
        }
    }
    void leftAlgorithm(char a, char c)
    {
        rotateByClock(a); 
        rotateByClock('y'); 
        rotateByClock(a);
        rotateByClock(a); 
        rotateByClock(a);
        whiteBottom(c);
    }
    void whiteLeftAlg(char q) {
        if (blue[5] == 'w' || red[5] == 'w' || green[5] == 'w' || orange[5] == 'w')
        {
            if (blue[5] == 'w' && red[1] == q)
            {
                leftAlgorithm('r', q);
            }
            if (red[5] == 'w' && green[1] == q)
            {
                leftAlgorithm('g', q);
            }
            if (green[5] == 'w' && orange[1] == q)
            {
                leftAlgorithm('o', q);
            }
            if (orange[5] == 'w' && blue[1] == q)
            {
                leftAlgorithm('b', q);
            }
        }
    }

    void topAlgorithm(char a, char b, char c) {
        rotateByClock(a); 
        rotateByClock(a);
        rotateByClock(a);
        rotateByClock('w');
        rotateByClock(b);
        rotateByClock('w');
        rotateByClock('w');
        rotateByClock('w');
        whiteBottom(c);
    }
    void whiteTopAlg(char q)
    {
        if (blue[7] == 'w' && white[0] == q)
        {
            topAlgorithm('b', 'r', q);
        }
        if (red[7] == 'w' && white[2] == q)
        {
            topAlgorithm('r', 'g', q);
        }
        if (green[7] == 'w' && white[4] == q)
        {
            topAlgorithm('g', 'o', q);
        }
        if (orange[7] == 'w' && white[6] == q)
        {
            topAlgorithm('o', 'b', q);
        }
    }
    void invertingAlgorithm(char a, char b, char c) {
        rotateByClock(a);
        rotateByClock(b);
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock(b);
        rotateByClock(b);
        rotateByClock(b);
        rotateByClock(a);
        rotateByClock(a);
        rotateByClock(a);
        whiteBottom(c);
    }
    void whiteBottomInverted(char q) {
        if (blue[3] == 'w' || red[3] == 'w' || green[3] == 'w' || orange[3] == 'w')
        {
            if (blue[3] == 'w' && yellow[0] == q)
            {
                invertingAlgorithm('b', 'r', q);
            }
            if (red[3] == 'w' && yellow[2] == q)
            {
                invertingAlgorithm('r', 'g', q);
            }
            if (green[3] == 'w' && yellow[4] == q)
            {
                invertingAlgorithm('g', 'o', q);
            }
            if (orange[3] == 'w' && yellow[6] == q)
            {
                invertingAlgorithm('o', 'b', q);
            }
        }
    }

    void whiteCornersLeftAlg()
    {
        rotateByClock('b');
        rotateByClock('b'); 
        rotateByClock('b');
        rotateByClock('y'); 
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock('b');
    }
    void whiteCornersRightAlg() {
        rotateByClock('r');
        rotateByClock('y');
        rotateByClock('r'); 
        rotateByClock('r'); 
        rotateByClock('r');
    }

    // Алгоритмы для сборки среднего слоя
    void middleLayerLeftAlg(char left, char center) {
        rotateByClock('y'); 
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock(left);
        rotateByClock(left);
        rotateByClock(left);
        rotateByClock('y');
        rotateByClock(left);
        rotateByClock('y');
        rotateByClock(center);
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock(center);
        rotateByClock(center);
        rotateByClock(center);
    }
    void middleLayerRightAlg(char center, char right) {
        rotateByClock('y');
        rotateByClock(right);
        rotateByClock('y');
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock(right); 
        rotateByClock(right);
        rotateByClock(right);
        rotateByClock('y');
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock(center);
        rotateByClock(center);
        rotateByClock(center);
        rotateByClock('y');
        rotateByClock(center);
    }

    // Алгоритмы для сборки нижнего слоя, желтый
    void yellowCrossAlg() {
        rotateByClock('r');
        rotateByClock('y');
        rotateByClock('g');
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('r');
        rotateByClock('r');
        rotateByClock('r');
    }
    void yellowCornersAlg() {
        rotateByClock('g');
        rotateByClock('y');
        rotateByClock('g'); 
        rotateByClock('g'); 
        rotateByClock('g');
        rotateByClock('y');
        rotateByClock('g');
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock('g'); 
        rotateByClock('g'); 
        rotateByClock('g');
    }
    void yellowCornersOrientationAlg() {
        rotateByClock('g'); 
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('r');
        rotateByClock('g');
        rotateByClock('g'); 
        rotateByClock('g');
        rotateByClock('o');
        rotateByClock('o');
        rotateByClock('g');
        rotateByClock('r');
        rotateByClock('r');
        rotateByClock('r');
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('o');
        rotateByClock('o');
        rotateByClock('g');
        rotateByClock('g');
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock('y');
    }
    void yellowEdgesColourLocationRight() {
        rotateByClock('r'); 
        rotateByClock('r');
        rotateByClock('y');
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock('g');
        rotateByClock('g'); 
        rotateByClock('g');
        rotateByClock('b');
        rotateByClock('r'); 
        rotateByClock('r');
        rotateByClock('b'); 
        rotateByClock('b'); 
        rotateByClock('b');
        rotateByClock('g');
        rotateByClock('y'); 
        rotateByClock('y');
        rotateByClock('y');
        rotateByClock('r');
        rotateByClock('r');
    }
    void yellowEdgesColourLocationLeft() {
        rotateByClock('r'); 
        rotateByClock('r');
        rotateByClock('y');
        rotateByClock('b');
        rotateByClock('g'); 
        rotateByClock('g'); 
        rotateByClock('g');
        rotateByClock('r'); 
        rotateByClock('r');
        rotateByClock('b'); 
        rotateByClock('b');
        rotateByClock('b');
        rotateByClock('g');
        rotateByClock('y');
        rotateByClock('r');
        rotateByClock('r');
    }
    /*-----------------------------------------------------------*/

    /*------------Функции сборки кубика рубика------------*/

    // Сборка белого верхнего креста
    void solveWhiteCross() {
        char prefer[4] = { 'b','r','g','o' };
        for (int i = 0; i < 4; i++)
        {
            if (white[0] == 'w' && blue[7] == prefer[i]) {
                rotateByClock('b');
            }
            if (white[2] == 'w' && red[7] == prefer[i]) {
                rotateByClock('r');
            }
            if (white[4] == 'w' && green[7] == prefer[i]) {
                rotateByClock('g');
            }
            if (white[6] == 'w' && orange[7] == prefer[i]) {
                rotateByClock('o');
            }
            whiteBottom(prefer[i]);
            whiteBottomInverted(prefer[i]);
            whiteLeftAlg(prefer[i]);
            whiteRightAlg(prefer[i]);
            whiteTopAlg(prefer[i]);
            if (i != 0)
            {
                while (blue[7] != 'b') {
                    rotateByClock('w');
                }
            }
            if (white[0] == 'w' && white[2] == 'w' && white[4] == 'w' && white[6] == 'w' && blue[7] == 'b' && red[7] == 'r' && green[7] == 'g' && orange[7] == 'o')
            {
                break;
            }
        }
    }
    // Сборка углов при белом кресте
    void solveWhiteCorners() {
        while (red[0] != 'r' || red[6] != 'r' || blue[0] != 'b' || blue[6] != 'b' || orange[0] != 'o' || orange[6] != 'o' || green[0] != 'g' || green[6] != 'g')
        {
            while (red[7] != 'r')
            {
                rotateByClock('w');
            }
            if (blue[4] == 'w' || red[4] == 'w' || green[4] == 'w' || orange[4] == 'w')
            {
                while (blue[4] != 'w')
                {
                    rotateByClock('y');
                }
                while (red[2] != red[7])
                {
                    rotateByClock('w');
                }
                whiteCornersLeftAlg();
                while (red[7] != 'r')
                {
                    rotateByClock('w');
                }
            }
            else if (blue[2] == 'w' || red[2] == 'w' || green[2] == 'w' || orange[2] == 'w')
            {
                while (red[2] != 'w')
                {
                    rotateByClock('y');
                }
                while (red[7] != yellow[1])
                {
                    rotateByClock('w');
                }
                whiteCornersRightAlg();
                while (red[7] != 'r')
                {
                    rotateByClock('w');
                }
            }
            else if (yellow[1] == 'w' || yellow[3] == 'w' || yellow[5] == 'w' || yellow[7] == 'w')
            {
                while (yellow[1] != 'w')
                {
                    rotateByClock('y');
                }
                while (red[2] != blue[7])
                {
                    rotateByClock('w');
                }
                rotateByClock('b'); 
                rotateByClock('b'); 
                rotateByClock('b');
                rotateByClock('y'); 
                rotateByClock('y');
                rotateByClock('b');
                while (blue[4] != 'w')
                {
                    rotateByClock('y');
                }
                while (red[2] != red[7])
                {
                    rotateByClock('w');
                }
                whiteCornersLeftAlg();
                while (red[7] != 'r')
                {
                    rotateByClock('w');
                }
            }
            else
            {
                while (red[7] == red[0])
                {
                    rotateByClock('w');
                }
                whiteCornersLeftAlg();
                while (red[7] != 'r')
                {
                    rotateByClock('w');
                }
            }
        }
    }
    //Сборка среднего слоя
    void solveMiddleLayer() {
        while (red[5] != 'r' || red[1] != 'r' || blue[1] != 'b' || blue[5] != 'b' || orange[1] != 'o' || orange[5] != 'o' || green[1] != 'g' || green[5] != 'g')
        {

            if ((orange[1] != 'o' && green[5] != 'g') && (orange[1] != 'y' || green[5] != 'y'))
            {
                while (green[3] != 'y' && yellow[4] != 'y')
                {
                    rotateByClock('y');
                }
                middleLayerRightAlg('g', 'o');
            }

            else if ((orange[5] != 'o' && blue[1] != 'b') && (orange[5] != 'y' || blue[1] != 'y'))
            {
                while (orange[3] != 'y' && yellow[6] != 'y')
                {
                    rotateByClock('y');
                }
                middleLayerRightAlg('o', 'b');
            }

            else if ((blue[5] != 'b' && red[1] != 'r') && (blue[5] != 'y' || red[1] != 'y'))
            {
                while (blue[3] != 'y' && yellow[0] != 'y')
                {
                    rotateByClock('y');
                }
                middleLayerRightAlg('b', 'r');
            }

            else if ((red[5] != 'r' && green[1] != 'g') && (red[5] != 'y' || green[1] != 'y'))
            {
                while (red[3] != 'y' && yellow[2] != 'y')
                {
                    rotateByClock('y');
                }
                middleLayerRightAlg('r', 'g');
            }

            while (red[3] == 'y' || yellow[2] == 'y')
            {
                rotateByClock('y');
            }

            if (red[3] == 'r' && yellow[2] != 'y')
            {
                if (yellow[2] == 'g')
                {
                    middleLayerRightAlg('r', 'g');
                }
                else if (yellow[2] = 'b')
                {
                    middleLayerLeftAlg('b', 'r');
                }
            }
            else if (red[3] == 'b' && yellow[2] != 'y')
            {
                rotateByClock('y');
                if (yellow[0] == 'r')
                {
                    middleLayerRightAlg('b', 'r');
                }
                else if (yellow[0] = 'o')
                {
                    middleLayerLeftAlg('o', 'b');
                }
            }
            else if (red[3] == 'o' && yellow[2] != 'y')
            {
                rotateByClock('y'); rotateByClock('y');
                if (yellow[6] == 'b')
                {
                    middleLayerRightAlg('o', 'b');
                }
                else if (yellow[6] = 'g')
                {
                    middleLayerLeftAlg('g', 'o');
                }
            }
            else if (red[3] == 'g' && yellow[2] != 'y')
            {
                rotateByClock('y'); rotateByClock('y'); rotateByClock('y');
                if (yellow[4] == 'o')
                {
                    middleLayerRightAlg('g', 'o');
                }
                else if (yellow[4] = 'r')
                {
                    middleLayerLeftAlg('r', 'g');
                }
            }
        }
    }
    // Сборка нижнего желтого креста
    void solveYellowCross() {
        while (yellow[0] != 'y' || yellow[2] != 'y' || yellow[4] != 'y' || yellow[6] != 'y')
        {
            if ((yellow[0] == 'y' && yellow[6] == 'y') || (yellow[4] == 'y' && yellow[6] == 'y')
                || (yellow[2] == 'y' && yellow[4] == 'y') || (yellow[0] == 'y' && yellow[2] == 'y'))
            {
                while (yellow[0] != 'y' && yellow[6] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCrossAlg();
            }
            if ((yellow[2] == 'y' && yellow[6] == 'y') || (yellow[0] == 'y' && yellow[4] == 'y'))
            {
                while (yellow[0] != 'y' && yellow[4] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCrossAlg();
                yellowCrossAlg();
            }
            else if (yellow[8] == 'y')
            {
                yellowCrossAlg();
                rotateByClock('y');
                yellowCrossAlg();
                yellowCrossAlg();
            }
        }
    }
    // Сборка углов при нижнем слое
    void solveYellowCorners() {
        while (yellow[1] != 'y' || yellow[3] != 'y' || yellow[5] != 'y' || yellow[7] != 'y')
        {
            if ((yellow[1] == 'y' && yellow[3] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
                || (yellow[3] == 'y' && yellow[1] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
                || (yellow[5] == 'y' && yellow[1] != 'y' && yellow[3] != 'y' && yellow[7] != 'y')
                || (yellow[7] == 'y' && yellow[1] != 'y' && yellow[3] != 'y' && yellow[5] != 'y'))
            {
                while (yellow[1] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
            else if ((green[2] == 'y' && green[4] == 'y' && yellow[1] == 'y' && yellow[7] == 'y')
                || (orange[2] == 'y' && orange[4] == 'y' && yellow[1] == 'y' && yellow[3] == 'y')
                || (blue[2] == 'y' && blue[4] == 'y' && yellow[3] == 'y' && yellow[5] == 'y')
                || (red[2] == 'y' && red[4] == 'y' && yellow[5] == 'y' && yellow[7] == 'y'))
            {
                while (red[2] != 'y' && red[4] != 'y' && yellow[5] != 'y' && yellow[7] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
            else if ((red[4] == 'y' && orange[2] == 'y' && yellow[1] == 'y' && yellow[7] == 'y')
                || (blue[2] == 'y' && green[4] == 'y' && yellow[1] == 'y' && yellow[3] == 'y')
                || (red[2] == 'y' && orange[4] == 'y' && yellow[3] == 'y' && yellow[5] == 'y')
                || (blue[4] == 'y' && green[2] == 'y' && yellow[5] == 'y' && yellow[7] == 'y'))
            {
                while (red[2] != 'y' && orange[4] != 'y' && yellow[3] != 'y' && yellow[5] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
            else if ((green[2] == 'y' && green[4] == 'y' && blue[2] == 'y' && blue[4] == 'y')
                || (red[2] == 'y' && red[4] == 'y' && orange[2] == 'y' && orange[4] == 'y'))
            {
                while (green[2] != 'y' && green[4] != 'y' && blue[2] != 'y' && blue[4] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
            else if ((green[2] == 'y' && orange[2] == 'y' && orange[4] == 'y' && blue[4] == 'y')
                || (red[4] == 'y' && orange[2] == 'y' && blue[2] == 'y' && blue[4] == 'y')
                || (red[2] == 'y' && red[4] == 'y' && green[4] == 'y' && blue[2] == 'y')
                || (green[2] == 'y' && green[4] == 'y' && orange[4] == 'y' && red[2] == 'y'))
            {
                while (green[2] != 'y' && orange[2] != 'y' && orange[4] != 'y' && blue[4] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
            else if ((yellow[1] == 'y' && yellow[5] == 'y' && yellow[3] != 'y' && yellow[7] != 'y')
                || (yellow[3] == 'y' && yellow[7] == 'y' && yellow[1] != 'y' && yellow[5] != 'y'))
            {
                while (red[2] != 'y' && green[4] != 'y')
                {
                    rotateByClock('y');
                }
                yellowCornersAlg();
            }
        }
    }
    // Корректировка ориентации нижних углов
    void solveYellowCornerOrientation() {
        while (red[2] != 'r' || red[4] != 'r' || green[2] != 'g' || green[4] != 'g'
            || orange[2] != 'o' || orange[4] != 'o' || blue[2] != 'b' || blue[4] != 'b')
        {
            if ((red[2] == red[4]) || (green[2] == green[4]) || (orange[2] == orange[4]) || (blue[2] == blue[4]))
            {
                while (orange[2] != orange[4])
                {
                    rotateByClock('y');
                }
                yellowCornersOrientationAlg();
                while (blue[2] != 'b')
                {
                    rotateByClock('y');
                }
            }
            else
            {
                while (orange[4] != 'o' && red[4] != 'r')
                {
                    rotateByClock('y');
                }
                yellowCornersOrientationAlg();
                while (orange[2] != orange[4])
                {
                    rotateByClock('y');
                }
                yellowCornersOrientationAlg();
                while (blue[2] != 'b')
                {
                    rotateByClock('y');
                }
            }
        }
    }
    // Выставление правильного расположения углов на нижнем слое относительно цвета
    void solveYellowEdgesColourLocation() {
        while (red[2] != 'r')
        {
            rotateByClock('r');
        }
        if (red[3] == 'o' && orange[3] == 'r' && blue[3] == 'g' && green[3] == 'b')
        {
            yellowEdgesColourLocationLeft();
        }
        else if (red[3] == 'b' && blue[3] == 'r')
        {
            yellowEdgesColourLocationLeft();
        }
        else if (red[3] == 'g' && green[3] == 'r')
        {
            yellowEdgesColourLocationLeft();
        }
        while (orange[2] != orange[3])
        {
            rotateByClock('y');
        }
        if (red[3] == green[2])
        {
            yellowEdgesColourLocationRight();
        }
        else if (red[3] == blue[2])
        {
            yellowEdgesColourLocationLeft();
        }
        while (red[3] != 'r')
        {
            rotateByClock('y');
        }
    }
    /*----------------------------------------------------*/
    bool correctEdge(char a, char b, map<pair<char, char>, int> *edges) {
        
        bool found = false;
        
        if (edges->count({ a,b })) {
            (*edges)[{a, b}] += 1;
            found = true;
        }

        if (edges->count({ b,a })) {
            (*edges)[{b,a}] += 1;

            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }

        return found;
    }
    bool correctCorner(char a, char b, char c, map<tuple<char, char, char>, int>* corners) {

        bool found = false;
        
        if (corners->count({ a,b,c })) {
            (*corners)[{a, b, c }] += 1;
            found = true;
        }
        if (corners->count({ a,c,b })) {
            (*corners)[{a, c, b}] += 1;
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }
        if (corners->count({ b,c,a })) {
            (*corners)[{b,c,a}] += 1;
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }
        if (corners->count({ b,a,c })) {
            (*corners)[{b,a,c}] += 1;
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }
        if (corners->count({ c,b,a })) {
            (*corners)[{c,b,a}] += 1;
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }

        if (corners->count({ c,a,b })) {
            (*corners)[{c,a,b}] += 1;
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }
        return found;
    }
    
public:
    Cube(): 
        white{'w','w','w','w','w','w', 'w','w','w'},
        red{ 'r','r','r','r','r','r','r','r','r' },
        orange{'o','o','o','o','o','o', 'o','o','o'},
        blue{'b','b','b','b','b','b', 'b','b','b'},
        green{'g','g','g','g','g','g', 'g','g','g'},
        yellow{'y','y','y','y','y','y', 'y','y','y'}
    {}

	void readCubeFromKeyboard() {

		readSideFromKeyboard(white);
		readSideFromKeyboard(red);
		readSideFromKeyboard(orange);
		readSideFromKeyboard(blue);
		readSideFromKeyboard(green);
		readSideFromKeyboard(yellow);

	}
	void readCubeFromFile() {
		cout << "Введите имя файла: ";
		string fileName;
		cin >> fileName;

		ifstream fi(fileName);

		readSideFromFile(white, fi);
		readSideFromFile(red, fi);
		readSideFromFile(orange, fi);
		readSideFromFile(blue, fi);
		readSideFromFile(green, fi);
		readSideFromFile(yellow, fi);

        fi.close();

	}
	void randomCube() {
        char sides[6] = { 'w', 'r', 'o', 'b', 'g', 'y' };
        cout << "------!MIXING!------ \n";

        int iterationsCount, rotationCount, sideByNumber;

        const int MinimalIterations = 100;
        const int MaxIterations = 200;

        const int MinimalRotationCount = 1;
        const int MaxRotationCount = 3;

        const int MinimalSide = 0;
        const int MaxSide = 5;

        iterationsCount = MinimalIterations + rand() % MaxIterations;

        for (int i = 0; i < iterationsCount; i++) {
            rotationCount = MinimalRotationCount + rand() % MaxRotationCount;
            sideByNumber = MinimalSide + rand() % MaxSide;

            for (int j = 0; j < rotationCount; j++) {
                rotateByClock(sides[sideByNumber]);
            }
        }
        cout << "------!MIXING FINISHED!------ \n";
	}

	void showCube() {
        cout << "Белая сторона: ";
		displaySide(white);
        cout << "Красная сторона: ";
		displaySide(red);
        cout << "Ораньжевая сторона: ";
		displaySide(orange);
        cout << "Синяя сторона: ";
		displaySide(blue);
        cout << "Зеленая сторона: ";
		displaySide(green);
        cout << "Желтая сторона: ";
		displaySide(yellow);
	}

	bool correctCube() {

        // В массиве хранится массив, показывающий какие два цвета принадлежат данному двусоставному элементу, и счетчик сколько данный элемент встречается
        map<pair<char, char>, int> edges;
        // В массиве хранится массив, показывающий какие три цвета принадлежат углу, и счетчик того, сколько данный элемент встречается
        map<tuple<char, char, char>, int> corners;

        // Ожидаемые ребра (двусоставные блоки)
        edges[make_pair('w','g')] = 0;
        edges[make_pair('w', 'o')] = 0;
        edges[make_pair('w', 'b')] = 0;
        edges[make_pair('w', 'r')] = 0;

        edges[make_pair('y', 'r')] = 0;
        edges[make_pair('y', 'g')] = 0;
        edges[make_pair('y', 'o')] = 0;
        edges[make_pair('y', 'b')] = 0;

        edges[make_pair('b', 'o')] = 0;
        edges[make_pair('b', 'r')] = 0;

        edges[make_pair('r', 'g')] = 0;

        edges[make_pair('g', 'o')] = 0;

        // Ожидаемые углы (трехсоставные блоки)
        corners[make_tuple('w', 'r', 'g')] = 0;
        corners[make_tuple('w', 'r', 'b')] = 0;
        corners[make_tuple('w', 'o', 'g')] = 0;
        corners[make_tuple('w', 'o', 'b')] = 0;

        corners[make_tuple('y', 'r', 'b')] = 0;
        corners[make_tuple('y', 'r', 'g')] = 0;
        corners[make_tuple('y', 'g', 'o')] = 0;
        corners[make_tuple('y', 'o', 'b')] = 0;

        // Проверка должны ли существовать такие ребра и сколько их в предполагаемом кубике
        if (!correctEdge(white[4], green[7], &edges)) return false;
        if (!correctEdge(white[6], orange[7], &edges)) return false;
        if (!correctEdge(white[0], blue[7], &edges)) return false;
        if (!correctEdge(white[2], red[7], &edges)) return false;

        if (!correctEdge(yellow[2], red[3], &edges)) return false;
        if (!correctEdge(yellow[4], green[3], &edges)) return false;
        if (!correctEdge(yellow[6], orange[3], &edges)) return false;
        if (!correctEdge(yellow[0], blue [3] , &edges)) return false;

        if (!correctEdge(blue[1], orange[5], &edges)) return false;
        if (!correctEdge(blue[5], red[1], &edges)) return false;

        if (!correctEdge(red[5], green[1], &edges)) return false;

        if (!correctEdge(green[5], orange[1], &edges)) return false;

        // Проверка должны ли существовать такие углы и сколько их в предполагаемом кубике
        if (!correctCorner(white[3], red[6], green[0], &corners)) return false;
        if (!correctCorner(white[1], red[0], blue[6], &corners)) return false;
        if (!correctCorner(white[5], orange[6], green[6], &corners)) return false;
        if (!correctCorner(white[7], orange[6], blue[0], &corners)) return false;

        if (!correctCorner(yellow[1], red[2], blue[4], &corners)) return false;
        if (!correctCorner(yellow[3], red[4], green[2], &corners)) return false;
        if (!correctCorner(yellow[5], green[4], orange[2], &corners)) return false;
        if (!correctCorner(yellow[7], orange[4], blue[2], &corners)) return false;

        for (auto& item : edges) {
            if (item.second != 1) {
                return false;
            }
        }

        for (auto& item : corners) {
            if (item.second != 1) {
                return false;
            }
        }
        return true;
	}
    
    void solve() {
        solveWhiteCross();
        solveWhiteCorners();
        solveMiddleLayer();
        solveYellowCross();
        solveYellowCorners();
        solveYellowCornerOrientation();
        solveYellowEdgesColourLocation();
    }
};

Cube initCube(char flag) {
	Cube cube;
	switch (flag) {
	case ('f'): {
		cube.readCubeFromFile();
		break;
	};
	case('r'): {
		cube.randomCube();
		break;
	};
	case('k'): {
		cube.readCubeFromKeyboard();
		break;
	}
	}

	return cube;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Выберите способ конфигурации : \n" <<
		"		k - с клавиатуры вручную\n" <<
		"		r - случайная комбинация\n" <<
		"		f - чтение из файла\n";
	char flag;
	cin >> flag;

	Cube cube;
	cube = initCube(flag);

    if (!cube.correctCube()) {
        cout << "Некорректная конфигурация куба\n";
        exit(-1);
    }

    cube.showCube();

    cout << "Сторона вращается на 90 градусов по часовой стрелке: \n";

    cube.solve();
    cube.showCube();

	return 0;
}