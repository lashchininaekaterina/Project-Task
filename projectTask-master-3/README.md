1. Данное задание является одной из возможностей получить баллы. Критерии его оценки перечислены ниже. 
Приложение нужно собрать в QT-creator.
    1) Скопируйте все файлы данного приложения и разархивируйте их.
    3) Ваше приложение это разархивированная вами папка, она включает следующие файлы: examplemodel.cpp, examplemodel.h, main.cpp, mainwindow.cpp, mainwindow.h, clusters.cpp, clusters.h, readWrite.cpp, readWrite.h, clusters.txt, siluettes.txt и другие (см editor.jpg).
    4) Запустите приложение (откройте QT creator и затем откройте существующее приложение выбирая файл untitled.pro)
    5) На форме (mainwindow.ui) расположены 2 tableView элемента и 4 pushButton, textEdit и lineEdit (см form.jpg)
![form](https://github.com/marymex/projectTask/blob/master/form.jpg)
    6) Приложение заполняет 2 таблицы tableView из 2 текстовых файлов clusters.txt и siluettes.txt
    7) При возникновении ошибки invalidPath (см invalidPath.jpg) нужно поменять путь до рабочего каталога, так как он указан неверно. 
![invalidPath](https://github.com/marymex/projectTask/blob/master/invalidPath.jpg)
    Для этого зайдите во вкладку Проекты (вертикальное меню слева в QT), нажмите Запустить под вашим compiling kit (см ChangePath.jpg)
![changePath](https://github.com/marymex/projectTask/blob/master/changePath.jpg)
    8) Замените неправильный путь на правильный путь в котором хранятся файлы вашего проекты (см ChangePath2.jpg).
![changePath2](https://github.com/marymex/projectTask/blob/master/changePath2.jpg)
  
2. Необходимо реализовать следующие функции:
    1) из readWrite.cpp
     void readpoints(std::ifstream& in, std::vector<mycluster::point>& points)
     void write_clusters(std::string outfilename, std::vector<mycluster::point>& points)
     void write_siluettes(std::string outfilename, std::vector<mycluster::cluster>& clusters)
    2) из cluster.h
     все элементы класса point
    3) из cluster.cpp
     void normalize_column(int ind, vector<point>& points)
     double dist2(const point &a, const point &b)
     double dist(const point &a, const point &b)
    4) из mainwindow.cpp
     разкомментировать все функции с пометкой //  UNCOMMENT ME WHEN FIXED после того, как данные функции реализованы


3. КРИТЕРИИ ОЦЕНИВАНИЯ ДАННОГО ЗАДАНИЯ:

    1) за полностью выполненные пункты 1) - 4) перечисленные ранее вы получаете x баллов (около 15)
    2) за добавление layouts на форму вы получите ещё x баллов
    4) за наследование и виртуальная(ые) функции для классов point и cluster вы получаете ещё x баллов.
    5) за шаблон презентации данных Model - View вы получаете ещё x баллов
    6) за реализацию нескольких форм и механизма переключения между ними вы получаете ещё x баллов. Инструкция как это сделать находится вот здесь https://evileg.com/ru/post/112/#header_anotherwindow.h
    7) за разработку системы обработки исключений (можно использовать материалы задания https://github.com/mgordenko/course_c_plus_23_24/tree/main/2023_2024_2nd_sem/week11/sem_22) вы получаете ещё x баллов
    8) за разработку и использование собственных виджетов вы получаете ещё x баллов.
    9) за реализацию алгоритмов кластеризации вы можете получить +x баллов за каждый алгоритм кластеризации.
    10) за использование task board вы получаете +5 баллов
    11) дополнительные баллы могут быть начислены за какую-либо другую функциональность. 


