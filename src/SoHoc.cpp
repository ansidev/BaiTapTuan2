#include "../include/SoHoc.h"


//SoHoc::SoHoc(void)
//{
//}
//
//
//SoHoc::~SoHoc(void)
//{
//}


#pragma region Ham tinh uoc so chung nho nhat cua hai so nguyen
int UCLN(int iA, int iB)
{
    iA = abs(iA);
    iB = abs(iB);
    if(iA == 0 && iB == 0)
    {
        return iA + iB;
    }
    while (iA != iB)
    {
        if(iA > iB)
            iA -= iB;
        else
            iB -= iA;
    }
    return iA;
}
#pragma endregion

#pragma region Ham tinh boi so chung nho nhat cua hai so nguyen
int BCNN(int iA, int iB)
{
    //Bien tam luu gia tri uoc chung lon nhat cua hai so
    int iUCLN = UCLN(iA, iB);
    //Bien tam luu gia tri boi chung nho nhat cua hai so 
    int iBCNN;
    if(iUCLN == 1)
    {
        iBCNN = abs(iA * iB);
    }
    else
    {
        iBCNN = abs(iA * iB) / iUCLN;
    }
    return iBCNN;
}
#pragma endregion