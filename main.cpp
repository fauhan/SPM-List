#include "parts.h"
    listkategori Lkategori;
    listmerek Q;
    listbarang B;
    address_kategori P,Ptemp;
    address_merek Pmerek;
    address_barang Pbarang;
    int pil,pil1;
    char kat[20], merek[20], rn[20], na[20], code[5];
    infotypekategori X,old;
    infotypemerek Y,oldm;
    infotypebarang Z, oldk ;
void menuinput (){
    system("cls");
    cout << "=== Menu Input SparePart==="<<endl;
    cout << " 1. Tambah kategori SparePart "<<endl;
    cout << " 2. Tambah merek dalam kategori"<<endl;
    cout << " 3. Tambah barang dalam merek"<<endl;
    cout << "Pilihan : ";
    cin >> pil1;
    switch(pil1){
    case 1:
        cout << "Masukkan kategori: "; cin >> X;
        insertFirstkategori(&Lkategori, X);
        break;
    case 2:
        cout << "Masukkan kategori: ";
        cin >> kat;
        //P = findElmKategori(Lkategori, kat);
        //Q = Lmerek(P);
        cout << "Masukkan merek: ";
        cin >> Y;
        Pmerek = alokasimerek(Y);
        insertFirstmerek(&Lkategori,kat,  Pmerek);
        getch();
        break;
    case 3 :
        cout << "Masukkan data barang"<<endl;
        cout << "======================="<<endl;
        cout << "Kode Barang : ";
        cin >> Z.kode;
        cout << "Nama Barang : ";
        cin >> Z.nama;
        cout << "Harga Barang : ";
        cin >>Z.harga;
        cout << "Jumlah Barang : ";
        cin >>Z.jumlah;
        Pbarang = alokasibarang(Z);
        cout << "-----------------------"<<endl;
        cout << " Search Kategori and Merek"<<endl;
        cout << "Masukkan kategori : ";
        cin >> kat;
        cout << "Masukkan merek : ";
        cin >> merek;
        insertFirstbarang(&Lkategori, kat, merek, Pbarang);
        break;
    }
};
void menuupdate(){
    system("cls");
    cout<< "===Menu Update Data Spare Part ==="<<endl;
    cout << "1. Menghapus Kategori Sparepart" << endl;
    cout << "2. Menghapus merek dalam kategori "<<endl;
    cout << "3. Menghapus Barang" << endl;
    cout << "4. Mengubah Kategori Spare Parts" << endl;
    cout << "5. Mengubah Merek Spare Parts"<<endl;
    cout << "6. Mengubah Kode Barang Spare Parts" << endl;
    cout << "7. Delete First kategori"<<endl;
    cout << "8. Delete Last Kategori"<<endl;
    cout << "Pilihan :";
    cin >> pil1;
    switch(pil1){
    case 1 :
        cout << endl;
        cout << "Hapus Kategori : ";
        cin >> kat;
        //P = findElmKategori(Lkategori, X);
        delSearchkategori(&Lkategori,kat);
        break;
    case 2 :
        cout << endl;
        cout << "Dari kategori : ";
        cin >> kat;
        //P = findElmKategori(Lkategori, X);
        cout << "Hapus Merek : ";
        cin >> merek;
        //Q = Lmerek(P);
        //Pmerek = findElmmerek(Q,Y);
        delSearchMerek(&Lkategori, kat, merek);
        break;
    case 3 :
        cout << endl;
        cout << "Dari Kategori: ";
        cin >> kat;
        cout << "\nDari Merek: ";
        cin >> merek;
        cout << "\nDari kode: ";
        cin >> code;
        delSearchBarang(&Lkategori, kat, merek, code);
        break;
    case 4 :
        cout<<"\n Kategori lama : ";
        cin >>old;
        cout<<"kategori baru : ";
        cin>>X;
        renamekategori(Lkategori, old, X);
        break;
    case 5 :
        cout<<" Merek lama : ";
        cin>>oldm;
        cout<<" Merek baru : ";
        cin>>Y;
        cout<<"----------------"<<endl;
        cout << "Cari Kategori : ";
        cin >>kat;
        renamemerek(Lkategori,kat,oldm,Y);
        break;
    case 6 :
        cout<<" Kode Barang lama : ";
        cin >>  oldk.kode;
        cout<<" Kode Barang baru : ";
        cin>>Z.kode;
        cout<<"----------------"<<endl;
        cout << "Cari Kategori : ";
        cin >>kat;
        cout << "Cari Merek : ";
        cin >> merek;
        renamekodebarang(Lkategori, kat, merek, oldk.kode, Z.kode);
        break;
    case 7 :
        delFirstkategori(&Lkategori, &P);
        cout << "delete first kategori berhasil"<<endl;
        break;
    case 8 :
        delLastKategori(&Lkategori, &P);
        cout << "delete Last kategori berhasil"<<endl;
        break;
    }
};
void menuview (){
    system("cls");
    cout << "=== Menu View SparePart==="<<endl;
    cout << " 1. View Kategori "<<endl;
    cout << " 2. View Merek"<<endl;
    cout << " 3. View Barang"<<endl;
    cout << " 4. View All"<<endl;
    cout << "Pilihan : ";
    cin >> pil1;
    switch(pil1){
    case 1 :
        viewkategori(Lkategori);
        break;
    case 2 :
        viewmerek(Lkategori);
        break;
    case 3 :
        viewbarang(Lkategori);
        break;
    case 4 :
        viewall(Lkategori);
        break;
    }
}
void cari(){
    system("cls");
    cout << "=== Menu Search SparePart==="<<endl;
    cout << " 1. Search Kategori "<<endl;
    cout << " 2. Search Merek"<<endl;
    cout << " 3. Search Barang"<<endl;
    cout << "Pilihan : ";
    cin >> pil1;
    switch(pil1){
    case 1 :
        cout<<"cari kategori : ";
        cin >>kat;
        findElmKategori1(Lkategori, kat);
        getch();
        break;
    case 2 :
        cout<<"cari merek : ";
        cin >>merek;
        cout<<"dari kategori : ";
        cin >>kat;
        P = findElmKategori(Lkategori, kat);
        Q = Lmerek(P);
        findElmmerek1(Q, merek);
        getch();
        break;
    case 3 :
        cout<<"cari kode barang : ";
        cin >>code;
        cout<<"dari kategori : ";
        cin >>kat;
        cout<<"dari merek : ";
        cin >>merek;
        P = findElmKategori(Lkategori, kat);
        Q = Lmerek(P);
        Pmerek = findElmmerek1(Q, merek);
        B = Lbarang(Pmerek);
        findElmkodebarang1(B, code);
        getch();
        break;
    }
}

int main()
{
    createkategori(&Lkategori);
    createmerek(&Q);
    createbarang(&B);
    do{
    system("cls");
    cout << "===== Main Menu ===="<<endl;
    cout << "1. Input Spare Part" << endl;
    cout << "2. View Data Spare Part" << endl;
    cout << "3. Edit Data Spare Part" << endl;
    cout << "4. Cari Data Spare Part" << endl;
    cout << "5. Exit" << endl;
    cout << "Pilih : " ;
    cin >> pil;
    switch(pil){
    case 1:
        menuinput();
        break;
    case 2:
        menuview();
        getch();
        break;
    case 3 :
        menuupdate();
        break;
    case 4 :
        cari();
        break;
    }
    }while(pil!=5);
    getch();
    return 0;
}
