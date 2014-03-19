#include "SoHoc.h"
#include "iostream"
using namespace std;

class PhanSo
{
private:
    int iTuSo;                          //Tu so
    int iMauSo;                         //Mau so
public:
    PhanSo Get();                       //Ham truy xuat gia tri cua phan so
    void Set(PhanSo);                   //Ham gan gia tri cua mot phan so khac cho phan so
    bool Nhap();                        //Ham nhap phan so tu ban phim
    void Xuat();                        //Ham in gia tri phan so ra man hinh
    PhanSo Cong(PhanSo);                //Ham cong mot phan so voi mot phan so
    PhanSo Cong(int);                   //Ham cong mot phan so voi mot so nguyen
    PhanSo Tru(PhanSo);                 //Ham tru mot phan so voi mot phan so
    PhanSo Tru(int);                    //Ham tru mot phan so voi mot so nguyen
    PhanSo Nhan(PhanSo);                //Ham nhan mot phan so voi mot phan so
    PhanSo Nhan(int);                   //Ham nhan mot phan so voi mot so nguyen
    PhanSo Chia(PhanSo);                //Ham chia mot phan so cho mot phan so
    PhanSo Chia(int);                   //Ham chia mot phan so cho mot so nguyen
    bool KiemTraTinhHopLe();
    PhanSo RutGon();                    //Ham rut gon mot phan so
    PhanSo TimPhanSoDoi();              //Ham tim phan so doi cua mot phan so
    PhanSo NghichDao();                 //Ham tim phan so nghich dao cua mot phan so
    void QuiDong(PhanSo &);             //Ham qui dong mau so cua hai phan so
    void SoSanh(PhanSo);                //Ham so sanh hai phan so 
    PhanSo TimPhanSoLonNhat(PhanSo);    //Ham tim phan so lon nhat trong hai phan so 
public:
    PhanSo(void);
    ~PhanSo(void);
    PhanSo(const PhanSo &);
    PhanSo(int, int);
};
