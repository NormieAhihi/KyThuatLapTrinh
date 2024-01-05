#include<iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef struct NhanVien{
	int ma;
    char ten[150];
    long double luong;
} nv;

struct Node{
	nv *data;
    Node *next;
};

//nhap thong tin nhan vien
nv *NhapNhanVien(){
    nv *nv = new NhanVien;
    cout << "Nhap MSNV: ";
    cin >> nv->ma;
    cin.ignore();
    cout << "Nhap ho va ten: ";
    gets(nv->ten);
    cout << "Nhap luong: ";
    cin >> nv->luong;
    return nv;
}

Node *CreateNode(NhanVien *nv)
{
    Node *pNode = new Node;
    if(pNode != NULL)
    {
        pNode->data = nv;
        pNode->next = NULL;
    }
    else
    {
        cout<<"Cap phat bo nho that bai!";
    }
    return pNode;
}

Node *addLast(Node *l, NhanVien *nv){
	Node *temp = CreateNode(nv);
    l->next = temp;
    return temp;
}

//hien thi danh sach
void printList(Node *l)
{
	int i = 1;
    Node *p = l;
    if(p == NULL)
    {
        cout << "Danh sach rong\n";
        return;
    }
    cout << "STT" << "\t" << "MSNV" << "\t" << "Ho va ten" << "\t" << "Luong" << endl;
    while(p != NULL)
    {
        nv *nv = p->data;
        cout << i << "\t" << nv->ma  << "\t" << nv->ten << "\t\t" << nv->luong << "\n";
        p = p->next;
        i++;
    }
}

//Xoa thong tin (theo MSNV)
void RemoveNode(Node *l,int ma, int &n)
{
    Node *pDel = l;
    if(pDel == NULL)
    {
        cout << "Danh sach rong!\n";
    }
    else
    {
        Node *pPre = NULL;
        while(pDel != NULL)
        {
            nv *nv = pDel->data;
            if(nv->ma == ma)
                break;
            pPre = pDel;
            pDel = pDel->next;
        }
        if(pDel == NULL)
        {
            cout << "khong tim thay MSNV\n" << ma;
        }
        else
        {
            if(pDel == l)
            {
                l = l->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
                n--;
            }
            else
            {
                pPre->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
                n--;
            }
        }
    }
}

//Sua thong tin luong cua nhan vien theo MSNV
void SuaLuong(Node *l){
	long double luong2;
	int ma;
	nv *nv;
	cout << "Nhap MSNV can sua: ";
	cin >> ma;
	cout << "Nhap lai luong moi: ";
	cin >> luong2;
	Node *p = l;
    if(p == NULL)
    {
        cout << "Danh sach rong!\n";
    }
    else
    {
        while(p != NULL)
        {
            nv = p->data;
            if(nv->ma == ma)
                break;
            p = p->next;
        }
        if(p == NULL)
        {
            cout << "khong tim thay MSNV\n" << ma;
        }
        else
        {
            nv->luong = luong2;
        }
    }
}

//Tinh luong trung bình cua cac nhan vien
long double LuongTB(Node *l, int n){
	long double tb = 0;
	Node *p = l;
	while (p != NULL){
		nv *nv  = p->data;
		tb += nv->luong;
		p = p->next;
	}
	return tb/n;
}

//Tim luong cua nhan vien cao nhat va in ra MSNV
int LuongCaoNhat(Node *l){
	int ma;
	Node *p = l;
	nv *nv;
	nv = p->data;
	long double max = nv->luong;
	ma = nv->ma;
	while (p != NULL){
		nv = p->data;
		if(max < nv->luong){
			max = nv->luong;
			ma = nv->ma;
		}
		p = p->next;
	}
	return ma;
}

int main(){
	int n, ma;
	long double tb;
	cout << "So luong nhan vien can nhap: ";
	cin >> n;
	NhanVien *nv = NhapNhanVien();
	Node *l = CreateNode(nv);
	Node *p = l;
	for(int i = 1; i < n; i++){
		nv = NhapNhanVien();
		p = addLast(p, nv);
	}
	printList(l);
	SuaLuong(l);
	printList(l);
	cout << "Nhap MSNV cua nhan vien can xoa thong tin: " ;
	cin >> ma;
	RemoveNode(l, ma, n);
	printList(l);
	tb = LuongTB(l, n);
	cout << "Luong TB cua cac nhan vien la: " << tb << endl;
	ma = LuongCaoNhat(l);
	cout << "MSNV cua nhan vien co luong cao nhat la: " << ma << endl;
}

