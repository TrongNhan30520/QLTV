void XuLyNhap_Chu(string & InPut, int toadoX, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	while (true) 
	{
		char c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;   
			}
		}
	}
}
void XuLyNhap_So(int& n, int toadoX, int& toadoY)
{
	int toadoXtam;
	string x;
	x = ChuyenSoSangString1(n);
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && whereX() < toadoX + 47)		
		{
			x.insert(x.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < x.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << x;
				gotoXY(toadoXtam, whereY());
			}
			else
			{
				cout << c;
			}
		}
		else if (c == 8 && whereX() > toadoX)
		{
			x.erase(x.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << x;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && x.length() > 0)// enter
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + x.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void ChonPhai(string& Phai, int& pointer2)
{
	ShowCur(0);
	int pointer1 = 100;
	while (true)
	{
		gotoXY(100, 17);
		cout << "Nam";
		gotoXY(115, 17);
		cout << "Nu";

		if (kbhit())
		{
			char c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (pointer1 == 100)
						pointer1 = 115;
					else
						pointer1 = 100;
				}
				else if (c == 77)
				{
					if (pointer1 == 115)
						pointer1 = 100;
					else
						pointer1 = 115;
				}
				else if (c == 72)
				{
					ShowCur(1);
					pointer2 = pointer2 - 3;
					break;
				}
				else if (c == 80)
				{
					pointer2 = pointer2 + 3;
					break;
				}
			}
			if (c == 13)
			{
				
				HighLight();
				if (pointer1 == 100)
				{
					gotoXY(100, 17);
					cout << "Nam";
					Phai = "Nam";
					pointer2 = pointer2 + 3;
				}
				else if (pointer1 == 115)
				{
					gotoXY(115, 17);
					cout << "Nu";
					gotoXY(100,17);
					Normal();
					cout<<"Nam";
					Phai = "Nu";
					pointer2 = pointer2 + 3;
				}
				Normal();
				break;
			}
		}

		gotoXY(pointer1, 17);
		HighLight();
		if (pointer1 == 100)
		{
			
			cout << "Nam";
		}
		else if (pointer1 == 115)
		{
			cout << "Nu";
		}
		Normal();
		Sleep(100);
	}
}
void Xuat1DocGia(TREE_TDG t,int toadoX, int toadoY)
{
	BodyTable();
	gotoXY(toadoX + 1, toadoY + 4);
	cout << CanDeuChuoi(ChuyenSoSangString(t->thedocgia.MaThe), 9);
	gotoXY(toadoX + 11, toadoY + 4);
	cout << CanDeuChuoi(t->thedocgia.Ho + " " + t->thedocgia.Ten, 39);
	gotoXY(toadoX + 51, toadoY + 4);
	cout << CanDeuChuoi(t->thedocgia.Phai, 9);
	gotoXY(toadoX + 61, toadoY + 4);
	cout << CanDeuChuoi(TrangThaiDocGia(t->thedocgia.TrangThai), 11);
	gotoXY(toadoX + 73, toadoY + 4);
	cout << CanDeuChuoi(ChuyenSoSangString(t->thedocgia.SoLuongSachDangMuon), 11);
}
void XuatDanhSachMuonCua1DocGia(MCONTRO DauS, TREE_TDG t, int toadoX, int toadoY)
{
	int j = 0;
	for (NODE_DOUBLELIST* k = t->thedocgia.DoubleList_MuonTra.First; k != NULL; k = k->right)
	{
		if (k->data.TrangThai == 0)
		{
			gotoXY(toadoX+1,toadoY+3);
			gotoXY(toadoX + 1, toadoY + 4 + j);
			cout << CanDeuChuoi(k->data.MaSach, 19);
			gotoXY(toadoX + 21, toadoY + 4 + j);
			cout << CanDeuChuoi(LayTenSach(DauS, k->data.MaSach), 40);
			gotoXY(toadoX + 62, toadoY + 4 + j);
			cout << CanDeuChuoi(ChuyenSoSangString(k->data.NgayMuon.Ngay) + "/" + ChuyenSoSangString(k->data.NgayMuon.Thang) + "/" + ChuyenSoSangString(k->data.NgayMuon.Nam), 19);
			gotoXY(toadoX + 82, toadoY + 4 + j);
			cout << CanDeuChuoi(TrangThaiMuonTra(k->data.TrangThai), 18);
			j = j + 2;
		}
	}
}
void XuLyNhap_NgayThangNam(int & n, int &toadoX, int & toadoY,int flag)
{
	int tam = n;
	int max;
	string min;
	if(flag==1) //nhap ngay thang
	{
		max=2;
		min="00";
	}
	else if(flag==2) //nhap nam
	{
		max=4;
		min="0000";
	}
	int toadoXtam;
	string x;
	if(n==0)
	{
		x=min;
	}
	else
	{
		x = ChuyenSoSangString1(n);
	}
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && x.length()<max)
		{
			x.insert(x.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < x.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "    ";
				gotoXY(toadoX, whereY());
				cout << x;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && x.length()>0)
		{
			x.erase(x.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "    ";
			gotoXY(toadoX, whereY());
			cout << x;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13)
		{
				if (x.empty())
				{
					n = tam;
					gotoXY(toadoX, whereY());
					if(n==0)
					{
						cout<<min;
					}
					else
					{
						cout<<ChuyenSoSangString1(tam);
					}
				}
				else
				{
					if(x=="00")
					{
						n=0;
					}
					else
					{
						n = atoi(x.c_str());
					}
				}
				toadoY= toadoY+3;
				return;
			
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && toadoX>BoxMain[0]+32 && toadoX>BoxMain[0]+32)
			{
				if (x.empty())
				{
					n = tam;
					gotoXY(toadoX, whereY());
					if(n==0)
					{
						cout<<min;
					}
					else
					{
						cout<<ChuyenSoSangString1(tam);
					}
				}
				else
				{
					if(x=="00")
					{
						n=0;
					}
					else
					{
						n = atoi(x.c_str());
					}
				}
				toadoX=toadoX-7;
				return;
			}
			else if (c == 77 && toadoX<BoxMain[0]+46)
			{
				if (x.empty())
				{
					n = tam;
					gotoXY(toadoX, whereY());
					if(n==0)
					{
						cout<<min;
					}
					else
					{
						cout<<ChuyenSoSangString1(tam);
					}
				}
				else
				{
					if(x=="00")
					{
						n=0;
					}
					else
					{
						n = atoi(x.c_str());
					}
				}
				toadoX=toadoX+7;
				return;
			}
			else if (c == 80)
			{
				if (x.empty())
				{
					n = tam;
					gotoXY(toadoX, whereY());
					if(n==0)
					{
						cout<<min;
					}
					else
					{
						cout<<ChuyenSoSangString1(tam);
					}
				}
				else
				{
					if(x=="00")
					{
						n=0;
					}
					else
					{
						n = atoi(x.c_str());
					}
				}
				toadoY = toadoY + 3;
				return;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = tam;
					gotoXY(toadoX, whereY());
					if(n==0)
					{
						cout<<min;
					}
					else
					{
						cout<<ChuyenSoSangString1(tam);
					}
				}
				else
				{
					if(x=="00")
					{
						n=0;
					}
					else
					{
						n = atoi(x.c_str());
					}
				}
				toadoY = toadoY + 3;
				return;
			}
		}
	}
}
void XuLyNhap_MaSach(string& InPut) 
{
	a : char c;
	 while (true)
	{
		if(kbhit)
		{
			c = getch();
			if(c == -32)
			{
				c=getch();
				goto a;
			}
			else
			{
				if ((c >= 48 && c <= 57) || c == '_' || (c >= 65 && c <= 90))
				{
					InPut.insert(InPut.begin() + InPut.length(), c);
					cout << c;
				}
				else if (c >= 97 && c <= 122)
				{
					c = c - 32;
					InPut.insert(InPut.begin() + InPut.length(), c);
					cout << c;
				}
				else if (c == 8 && InPut.length() > 0)
				{
					InPut.erase(InPut.begin() + InPut.length() - 1);
					cout << "\b";
					cout << " ";
					cout << "\b";
				}
				else if (c == 27)
				{
					InPut.clear();
					return;
				}
				else if (c == 13 && InPut.length() > 0)
				{
					break;
				}
			}
		}
	}
}
void Xuat1SachMuonCua1DocGia(MCONTRO DauS,MuonTra MT,int toadoX, int toadoY)
{
	gotoXY(toadoX + 1, toadoY );
	cout << CanDeuChuoi(MT.MaSach, 19);
	gotoXY(toadoX + 21, toadoY );
	cout << CanDeuChuoi(LayTenSach(DauS, MT.MaSach), 40);
	gotoXY(toadoX + 62, toadoY );
	cout << CanDeuChuoi(ChuyenSoSangString(MT.NgayMuon.Ngay) + "/" + ChuyenSoSangString(MT.NgayMuon.Thang) + "/" + ChuyenSoSangString(MT.NgayMuon.Nam), 19);
	gotoXY(toadoX + 82, toadoY );
	cout << CanDeuChuoi(TrangThaiMuonTra(MT.TrangThai), 18);
}
void XuLyNhap_ViTri(string& InPut, int toadoX, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)// n?u l?h?enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhap_MaDauSach(string & InPut, int toadoX, int& toadoY)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 10)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                    ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 10)
		{
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u l?h?enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhap_TenSach1(string & InPut, int toadoX, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)||
			c == '+' || c == '-' || c == '*' || c == '/'||c=='.'||c=='_') && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuatSachCua1DauSach(NODE_LIST *Sach[], int n, int vitri ,int toadoX, int toadoY)
{
	int j=0;
	for(int i=vitri;i<n;i++)
	{
		gotoXY(toadoX+2,toadoY+1+(j*2));
		cout<<CanDeuChuoi(Sach[i]->data.MaSach,24);
		gotoXY(toadoX+27,toadoY+1+(j*2));
		cout<<CanDeuChuoi(TrangThaiSach(Sach[i]->data.TrangThai),16);
		gotoXY(toadoX+44,toadoY+1+(j*2));
		cout<<CanDeuChuoi(Sach[i]->data.ViTri,16);
		j++;
	}
}
