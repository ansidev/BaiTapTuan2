#include "../include/PhanSo.h"

PhanSo::PhanSo()
{

}

PhanSo::~PhanSo()
{

}

//Ham truy xuat gia tri cua phan so
PhanSo PhanSo::Get()
{
    PhanSo psPhanSoTam;
    psPhanSoTam.iTuSo = this->iTuSo;
    psPhanSoTam.iMauSo = this->iMauSo;
    return psPhanSoTam;
}

//Ham gan gia tri cua mot phan so khac cho phan so
void PhanSo::Set(PhanSo psPhanSoTam)
{
    iTuSo = psPhanSoTam.iTuSo;
    iMauSo = psPhanSoTam.iMauSo;
}

//Ham khoi tao mot phan so tu mot phan so
PhanSo::PhanSo(const PhanSo &psPhanSo)
{
    iTuSo = iTuSo;
    iMauSo = iMauSo;
}

//Ham khoi tao mot phan so tu hai so nguyen
PhanSo::PhanSo(int iTu, int iMau)
{
    iTuSo = iTu;
    iMauSo = iMau;
}

//Ham nhap phan so tu ban phim
bool PhanSo::Nhap()
{
    PhanSo psPhanSoTam;
    cout<<"Nhap tu so va mau so: ";

    //Nhap gia tri tu ban phim vao mot bien tam
    cin>>psPhanSoTam.iTuSo;
    cin>>psPhanSoTam.iMauSo;
    cin.clear();
    cin.sync();

    //Kiem tra tinh hop le cua cac gia tri nhap vao
    bool bBienKiemTra = KiemTraTinhHopLe();
    
    //Neu gia tri nhap vao khong hop le thi xuat ra thong bao loi
    if(!bBienKiemTra)
    {
        cout<<"Loi: Mau so bang 0!"<<endl;
    }
    //Neu gia tri nhap vao hop le thi gan gia tri cho bien chinh
    else
    {
        cout<<"Gia tri hop le."<<endl;
        this->Set(psPhanSoTam);
    }
    return bBienKiemTra;
}

//Ham kiem tra tinh hop le cua phan so nhap vao tu ban phim
bool PhanSo::KiemTraTinhHopLe()
{
    if(iMauSo != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Ham xuat phan so ra man hinh
void PhanSo::Xuat()
{
    if(iMauSo != 0)
    {
        cout<<iTuSo<<"/"<<iMauSo;
    }
}

//Ham rut gon mot phan so
PhanSo PhanSo::RutGon()
{
    PhanSo psPhanSoToiGian = this->Get();
    //Bien tam de luu uoc chung lon nhat cua tu so va mau so cua mot phan so
    int iTemp = 1;
    //Tinh uoc chung lon nhat cua tu so va mau so
    iTemp = UCLN(psPhanSoToiGian.iTuSo, psPhanSoToiGian.iMauSo);

    if(iTemp == 1)
    {
        return psPhanSoToiGian;
    }
    else
    {
        //Rut gon phan so
        psPhanSoToiGian.iTuSo = iTuSo / iTemp;
        psPhanSoToiGian.iMauSo = iMauSo / iTemp;
        //Tra ve ket qua
        return psPhanSoToiGian;
    }
}

//Ham qui dong mau so cua hai phan so
void PhanSo::QuiDong(PhanSo &psPhanSo1)
{
    //Rut gon 2 phan so truoc khi thuc hien qui dong mau so
    this->RutGon();
    psPhanSo1.RutGon();
    
    //Neu hai phan so toi gian khac mau so thi moi thuc hien qui dong
    if(iMauSo != psPhanSo1.iMauSo)
    {
        //Bien tam luu gia tri boi chung nho nhat cua hai mau so
        int iBCNN = 1;
        iBCNN = BCNN(iMauSo, psPhanSo1.iMauSo);
        iTuSo *= (iBCNN / iMauSo);
        iMauSo = iBCNN;
        psPhanSo1.iTuSo *= (iBCNN / psPhanSo1.iMauSo);
        psPhanSo1.iMauSo = iBCNN;
    }
}

//Ham so sanh hai phan so
void PhanSo::SoSanh(PhanSo psPhanSo1)
{
    PhanSo psPhanSo2, psPhanSo3;
    psPhanSo2 = this->Get();
    psPhanSo3 = psPhanSo1;
    psPhanSo2.QuiDong(psPhanSo3);
    int iTemp = psPhanSo2.iTuSo - psPhanSo3.iTuSo;

    if(iTemp > 0)
    {
        this->Xuat();
        cout<<" > ";
        psPhanSo1.Xuat();
        cout<<endl;
    }

    if(iTemp == 0)
    {
        this->Xuat();
        cout<<" = ";
        psPhanSo1.Xuat();
        cout<<endl;
    }
    if(iTemp < 0)
    {
        this->Xuat();
        cout<<" < ";
        psPhanSo1.Xuat();
        cout<<endl;
    }
}

//Ham tim phan so lon nhat trong hai phan so
PhanSo PhanSo::TimPhanSoLonNhat(PhanSo psPhanSo1)
{
    PhanSo psPhanSo2, psPhanSo3;
    psPhanSo2 = this->Get();
    psPhanSo3 = psPhanSo1;
    psPhanSo2.QuiDong(psPhanSo3);
    int iTemp = psPhanSo2.iTuSo - psPhanSo3.iTuSo;

    if(iTemp >= 0)
    {
        return psPhanSo1;
    }
    else
    {
        return psPhanSo2;
    }
}

//Ham tim phan so doi cua mot phan so
PhanSo TimPhanSoDoi(PhanSo psPhanSo)
{
    PhanSo psPhanSo1;
    if(iMauSo > 0)
    {
        psPhanSo1.iTuSo = -1 * iTuSo;
        psPhanSo1.iMauSo = iMauSo;
    }
    if(iMauSo < 0)
    {
        psPhanSo1.iTuSo = iTuSo;
        psPhanSo1.iMauSo = -1 * iMauSo;
    }
    return psPhanSo1;

}

//Ham nghich dao mot phan so
PhanSo NghichDaoPhanSo(PhanSo psPhanSo)
{
    PhanSo psPhanSo1;
    if(iTuSo != 0)
    {
        if(iTuSo < 0)
        {
            psPhanSo1.iTuSo = -1 * iMauSo;
            iMauSo = -1 * iTuSo;
        }

        if(iTuSo > 0)
        {
            psPhanSo1.iTuSo = iMauSo;
            psPhanSo1.iMauSo = iTuSo;
        }
    }
    return psPhanSo1;
}

//Ham tinh tong hai phan so
PhanSo TinhTongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    PhanSo psTong;
    psPhanSo3 = psPhanSo1;
    psPhanSo4 = psPhanSo2;
    QuiDongPhanSo(psPhanSo3, psPhanSo4);
    psTong.iTuSo = psPhanSo3.iTuSo + psPhanSo4.iTuSo;
    psTong.iMauSo = psPhanSo3.iMauSo;
    psTong = RutGonPhanSo(psTong);
    return psTong;
}

//Ham tinh hieu hai phan so
PhanSo TinhHieuHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    //Tinh hieu cua hai phan so bang cach
    //tinh tong cua phan so thu nhat va phan so doi cua phan so thu hai
    return TinhTongHaiPhanSo(psPhanSo1, TimPhanSoDoi(psPhanSo2));
}

//Ham tinh tich hai phan so
PhanSo TinhTichHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psPhanSo3, psPhanSo4;
    PhanSo psTich;
    psPhanSo3 = RutGonPhanSo(psPhanSo1);
    psPhanSo4 = RutGonPhanSo(psPhanSo2);
    psTich.iTuSo = psPhanSo3.iTuSo * psPhanSo4.iTuSo;
    psTich.iMauSo = psPhanSo3.iMauSo * psPhanSo4.iMauSo;
    psTich = RutGonPhanSo(psTich);
    return psTich;
}

//Ham tinh thuong hai phan so
PhanSo TinhThuongHaiPhanSo(PhanSo psPhanSo1, PhanSo psPhanSo2)
{
    PhanSo psThuong;
    if(psPhanSo2.iTuSo != 0)
    {
        //Tinh thuong cua hai phan so bang cach
        //tinh tich cua phan so thu nhat va phan so nghich dao cua phan so thu hai
        psThuong = TinhTichHaiPhanSo(psPhanSo1, NghichDaoPhanSo(psPhanSo2));
    }
    return psThuong;
}