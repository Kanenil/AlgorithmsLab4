#include "Dictionary.cpp"

int main()
{
    Dictionary<char[20]> dict;
    char text1[20] = { "Adagio"};
    char text2[20] = { "Age of Anxiety" };
    char text3[20] = { "Agiochook" };
    char text4[20] = { "Alpine" };
    char text5[20] = { "American" };
    char text6[20] = { "Boreale" };
    char text7[20] = { "The Camp Meeting" };
    char text8[20] = { "Choral" };
    char text9[20] = { "Concord" };
    char text10[20] = { "Drum" };
    char text11[20] = { "The Four Seasons" };
    char text12[20] = { "Haffner" };
    char text13[20] = { "Hunt" };
    char text14[20] = { "Jeremiah" };
    char text15[20] = { "Kaddish" };
    dict.INSERT(text1);
    dict.INSERT(text2);
    dict.INSERT(text3);
    dict.INSERT(text4);
    dict.INSERT(text5);
    dict.INSERT(text6);
    dict.INSERT(text7);
    dict.INSERT(text8);
    dict.INSERT(text9);
    dict.INSERT(text10);
    dict.INSERT(text11);
    dict.INSERT(text12);
    dict.INSERT(text13);
    dict.INSERT(text14);
    dict.INSERT(text15);
    dict.PRINT();
    return 0;
}

