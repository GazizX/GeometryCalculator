#include <iostream>
#include "Line.h"
#include <vector>
#include "Tetragon.h"
#include "Parallelogram.h"
#include "MyRect.h"
#include "Rhomb.h"
#include "Square.h"
#include "Figure.h"
#include "functions.h"
#include "inputFunctions.h"
#include "Poly.h"
#include "functional"
#include "algorithm"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char ans;
    int i = 0;
    Figure* f;
    Line* line;
    Point* point;
    vector<Figure*> v;
    vector<Line*> l;
    vector<Point*> p;
    while (true) {
        printMainMenu();
        inputChar(ans);
        switch (ans)
        {
        case 'a':
            printFiguresMenu();
            inputChar(ans);
            switch (ans) {
            case 'a':
                f = inputCircle();
                inputInVector(v, f);
                break;
            case 'b':
                f = inputPoly();
                inputInVector(v, f);
                break;
            case 'c':
                f = inputTetragon();
                inputInVector(v, f);
                break;
            case 'd':
                f = inputTriangle();
                inputInVector(v, f);
                break;
            case 't':
                f = inputTrapezoid();
                inputInVector(v, f);
                break;
            case 'f':
                f = inputParallelogram();
                inputInVector(v, f);
                break;
            case 'g':
                f = inputRect();
                inputInVector(v, f);
                break;
            case 'r':
                f = inputRhomb();
                inputInVector(v, f);
                break;
            case 'q':
                f = inputSquare();
                inputInVector(v, f);
                break;
            case 'p':
                point = inputPoint();
                inputInVector(p, point);
                break;
            case 'l':
                line = inputLine();
                inputInVector(l, line);
                break;
            default:
                cout << "Некорректный ввод, попробуйте снова." << endl << endl;
                break;
            }
            break;
        case 'b': {
            if (v.empty() && l.empty() && p.empty()) {
                cout << "Для начала введите данные." << endl;
                break;
            }
            int i = 0;
            for_each(v.begin(), v.end(), [&i](Figure* fig) {
                i++;
                cout << "Фигура #" << i << endl;
                fig->toString();
                });
            i = 0;
            for_each(l.begin(), l.end(), [&i](Line* line) {
                i++;
                cout << "Прямая #" << i << endl;
                line->toString();
                });
            i = 0;
            for_each(p.begin(), p.end(), [&i](Point* point) {
                i++;
                cout << "Точка #" << i << endl << *point << endl;
                });
            break;
        }
        case 'x': {
            int n;
            printDeleteMenu();
            inputChar(ans);
            switch (ans) {
            case 'a':
                cout << "Введите номер фигуры для удаления: ";
                inputInt(n);
                if (n - 1 >= v.size() || n - 1 < 0)
                {
                    cout << "Некорректный ввод, попробуйте снова." << endl;
                    break;
                }
                v.erase(v.begin() + n - 1);
                cout << "Фигура удалена." << endl;
                break;
            case 'b':
                cout << "Введите номер прямой для удаления: ";
                inputInt(n);
                if (n - 1 >= l.size() || n - 1 < 0)
                {
                    cout << "Некорректный ввод, попробуйте снова." << endl;
                    break;
                }
                l.erase(l.begin() + n - 1);
                cout << "Прямая удалена." << endl;
                break;
            case 'c':
                cout << "Введите номер точки для удаления: ";
                inputInt(n);
                if (n - 1 >= p.size() || n - 1 < 0)
                {
                    cout << "Некорректный ввод, попробуйте снова." << endl;
                    break;
                }
                p.erase(p.begin() + n - 1);
                cout << "Точка удалена." << endl;
                break;
            default:
                cout << "Некорректный ввод, попробуйте снова." << endl << endl;
                break;
            }
            break;
        }
        case 'c': {
            if(v.empty()) {
                cout << "Для начала введите данные." << endl;
                break;
            }
            int a, b;
            cout << "Введите номер первой фигуры: ";
            inputInt(a);
            if (a - 1 >= v.size() || a - 1 < 0) {
                cout << "Некорректный ввод, попробуйте снова." << endl;
                break;
            }
            cout << "Введите номер второй фигуры: ";
            inputInt(b);
            if (b - 1 >= v.size() || b - 1 < 0) {
                cout << "Некорректный ввод, попробуйте снова." << endl;
                break;
            }
            cout << "Расстояние между центрами масс фигур: " << lengthOfSide(v[a - 1]->getCenterOfMass(), v[b - 1]->getCenterOfMass()) << endl;
            break;
        }
        case 'd':
            if (v.empty()) {
                cout << "Для начала введите данные." << endl;
                break;
            }
            printSortMenu();
            inputChar(ans);
            switch (ans) {
            case 'a':
                sort(v.begin(), v.end(), [](Figure*& left, Figure*& right) {
                    return (left->getSquare() < right->getSquare());
                });
                break;
            case 'b':
                sort(v.begin(), v.end(), [](Figure*& left, Figure*& right) {
                    return (left->getSquare() > right->getSquare());
                });
                break;
            case 'c':
                sort(v.begin(), v.end(), [](Figure*& left, Figure*& right) {
                    return (left->getPerimeter() < right->getPerimeter());
                    });
                break;
            case 'd':
                sort(v.begin(), v.end(), [](Figure*& left, Figure*& right) {
                    return (left->getPerimeter() > right->getPerimeter());
                    });
                break;
            default:
                cout << "Некорректный ввод, попробуйте снова." << endl << endl;
                break;
            }
            break;
        case 'p': {
            if (v.empty() || p.empty()) {
                cout << "Для начала введите данные." << endl;
                break;
            }
            int i = 0;
            int a, b;
            for_each(p.begin(), p.end(), [&i](Point* point) {
                i++;
                cout << "Точка #" << i << endl << *point << endl;
                });
            cout << "Выберите номер точки: ";
            inputInt(a);
            if (a - 1 >= p.size() || a - 1 < 0)
            {
                cout << "Некорректный ввод, попробуйте снова." << endl;
                break;
            }
            i = 0;
            for_each(v.begin(), v.end(), [&i](Figure* fig) {
                i++;
                cout << "Фигура #" << i << endl;
                fig->toString();
                });
            cout << "Выберите номер фигуры: ";
            inputInt(b);
            if (b - 1 >= p.size() || b - 1 < 0)
            {
                cout << "Некорректный ввод, попробуйте снова." << endl;
                break;
            }
            bool f;
            if (dynamic_cast<Poly*>(v[b - 1])) {
                f = isInFigure(*p[a - 1], static_cast<Poly*>(v[b - 1]));
            }
            else {
                f = isInFigure(*p[a - 1], static_cast<Circle*>(v[b - 1]));
            }
            if (f) {
                cout << "Точка находится внутри фигуры." << endl;
            }
            else {
                cout << "Точка не находится внутри фигуры." << endl;
            }
            break;
        }
        case 'f': {
            string path;
            cout << "Введите путь до файла: ";
            cin >> path;
            ifstream inputFile;
            inputFile.open(path);
            if (!inputFile)
            {
                cout << "Файл не существует." << endl;
                break;
            }
            char type;
            std::vector<Point> nodes;
            float x, y;
            try {
                while (inputFile) {
                    inputFile >> type;
                    switch (type) {
                    case 'a': {
                        double r;
                        Point c;
                        inputFile >> r >> c.x >> c.y;
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод круга, попробуйте снова");
                        f = Circle::createCircle(r, c);
                        if (!f) {
                            throw invalid_argument("Некорректный ввод круга, попробуйте снова");
                        }
                        else {
                            v.push_back(f);
                        }
                        break;
                    }
                    case 'b': {
                        int n;
                        inputFile >> n;
                        for (int i = 0; i < n; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод многоугольника, попробуйте снова");
                        f = Poly::createPoly(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод многоугольника, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    }
                    case 'd':
                        for (int i = 0; i < 3; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод треугольника, попробуйте снова");
                        f = Triangle::createTriangle(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод треугольника, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'c':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод четырехугольника, попробуйте снова");
                        f = Tetragon::createTetragon(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод четырехугольника, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 't':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод трапеции, попробуйте снова");
                        f = Trapezoid::createTrapezoid(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод трапеции, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'f':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод параллелограма, попробуйте снова");
                        f = Parallelogram::createParallelogram(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод параллелограма, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'g':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод прямоугольника, попробуйте снова");
                        f = Rect::createRect(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод прямоугольника, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'r':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод ромба, попробуйте снова");
                        f = Rhomb::createRhomb(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод ромба, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'q':
                        for (int i = 0; i < 4; i++) {
                            inputFile >> x >> y;
                            nodes.push_back(Point(x, y));
                        }
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод квадрата, попробуйте снова");
                        f = Square::createSquare(nodes);
                        if (!f)
                            throw invalid_argument("Некорректный ввод квадрата, попробуйте снова");
                        else {
                            v.push_back(f);
                        }
                        nodes.clear();
                        break;
                    case 'p':
                        inputFile >> x >> y;
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод точки, попробуйте снова");
                        point = new Point(x, y);
                        if (!point)
                            throw invalid_argument("Некорректный ввод точки, попробуйте снова");
                        else {
                            p.push_back(point);
                        }
                        break;
                    case 'l': {
                        Point p1, p2;
                        inputFile >> x >> y;
                        p1 = Point(x, y);
                        inputFile >> x >> y;
                        if (!inputFile)
                            break;
                        if (inputFile.fail())
                            throw invalid_argument("Некорректный ввод прямой, попробуйте снова");
                        p2 = Point(x, y);
                        line = Line::createLine(p1, p2);
                        if (!line)
                            throw invalid_argument("Некорректный ввод прямой, попробуйте снова");
                        else {
                            l.push_back(line);
                        }
                        break;
                    }
                    default:
                        cout << "Некорректный ввод, попробуйте снова." << endl << endl;
                        break;
                    }
                }
            }
            catch (const invalid_argument& error) {
                cout << error.what() << endl;
                break;
            }
            inputFile.close();
            break;
        }
        case 'o': {
            string path;
            cout << "Введите путь до файла: ";
            cin >> path;
            ofstream outFile(path);
            if (!outFile)
            {
                cout << "Файл не существует." << endl;
                break;
            }
            printOutputMenu();
            inputChar(ans);
            switch (ans) {
            case 'g':
                if (v.empty() && p.empty() && l.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                for_each(v.begin(), v.end(), [&outFile](Figure* fig) {
                    outFile << fig->convertForFile();
                    });
                for_each(l.begin(), l.end(), [&outFile](Line* line) {
                    outFile << line->convertForFile();
                    });
                for_each(p.begin(), p.end(), [&outFile](Point* point) {
                    outFile << point->convertForFile();
                    });
                break;
            case 'd': {
                if (v.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a, b;
                cout << "Запись фигур" << endl;
                cout << "Введите начало промежутка (левый индекс, нумерация с 1): ";
                inputInt(a);
                if (a - 1 >= v.size() - 1) {
                    cout << "Некорректный левый индекс, попробуйте снова." << endl;
                    break;
                }
                cout << "Введите конец промежутка (правый индекс, нумерация с 1): ";
                inputInt(b);
                if (b - 1 >= v.size() || b <= 0 || b <= a) {
                    cout << "Некорректный правый индекс, попробуйте снова." << endl;
                    break;
                }
                for_each(v.begin() + a - 1, v.begin() + b, [&outFile](Figure* fig) {
                    outFile << fig->convertForFile();
                    });
                break;
            }
            case 'e': {
                if (l.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a, b;
                cout << "Запись прямых" << endl;
                cout << "Введите начало промежутка (левый индекс, нумерация с 1): ";
                inputInt(a);
                if (a - 1 >= l.size() - 1) {
                    cout << "Некорректный левый индекс, попробуйте снова." << endl;
                    break;
                }
                cout << "Введите конец промежутка (правый индекс, нумерация с 1): ";
                inputInt(b);
                if (b - 1 >= l.size() || b <= 0 || b <= a) {
                    cout << "Некорректный правый индекс, попробуйте снова." << endl;
                    break;
                }
                for_each(l.begin() + a - 1, l.begin() + b, [&outFile](Line* line) {
                    outFile << line->convertForFile();
                    });
                break;
            }
            case 'f': {
                if (p.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a, b;
                cout << "Запись точек" << endl;
                cout << "Введите начало промежутка (левый индекс, нумерация с 1): ";
                inputInt(a);
                if (a - 1 >= p.size() - 1) {
                    cout << "Некорректный левый индекс, попробуйте снова." << endl;
                    break;
                }
                cout << "Введите конец промежутка (правый индекс, нумерация с 1): ";
                inputInt(b);
                if (b - 1 >= p.size() || b <= 0 || b <= a) {
                    cout << "Некорректный правый индекс, попробуйте снова." << endl;
                    break;
                }
                for_each(p.begin() + a - 1, p.begin() + b, [&outFile](Point* point) {
                    outFile << point->convertForFile();
                    });
                break;
            }
            case 'a': {
                if (v.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a;
                cout << "Запись фигуры" << endl;
                cout << "Введите индекс элемента, нумерация с 1: ";
                inputInt(a);
                if (a - 1 >= v.size()) {
                    cout << "Некорректный индекс, попробуйте снова." << endl;
                    break;
                }
                outFile << v[a - 1]->convertForFile();
                break;
            }
            case 'b': {
                if (l.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a;
                cout << "Запись прямой" << endl;
                cout << "Введите индекс элемента, нумерация с 1: ";
                inputInt(a);
                if (a - 1 >= l.size()) {
                    cout << "Некорректный индекс, попробуйте снова." << endl;
                    break;
                }
                outFile << l[a - 1]->convertForFile();
                break;
            }
            case 'c': {
                if (p.empty()) {
                    cout << "Для начала введите данные." << endl;
                    break;
                }
                int a;
                cout << "Запись точки" << endl;
                cout << "Введите индекс элемента, нумерация с 1: ";
                inputInt(a);
                if (a - 1 >= p.size()) {
                    cout << "Некорректный индекс, попробуйте снова." << endl;
                    break;
                }
                outFile << l[a - 1]->convertForFile();
                break;
            }
            default:
                cout << "Некорректный ввод, попробуйте снова." << endl;
                break;
            }
            outFile.close();
            break;
        }
        case 'v': {
            drawSurface(v, l, p);
            break;
        }
        case 'e':
            return 0;
        default:
            cout << "Некорректный ввод, попробуйте снова." << endl << endl;
            break;
        }
    }
    delete f;
    delete line;
    delete point;
    for (Figure* ptr : v) {
        delete ptr;
    }
    v.clear();
    for (Line* ptr : l) {
        delete ptr;
    }
    l.clear();
    for (Point* ptr : p) {
        delete ptr;
    }
    p.clear();
 }

