	void DelList(LIST_DMS& l)
	{
		if (l.First == NULL)
		{
			return;
		}
		NODE_LIST* t = l.First;
		l.First = l.First->next;
		delete t;
	}
void DelDoubleList(DOUBLELIST& l)
{
	if (l.First == NULL)
	{
		return;
	}
	else
	{
		NODE_DOUBLELIST* t = l.First;
		if (l.First->left == NULL)
		{
			l.First = NULL;
		}
		else
		{

			l.First = l.First->left;
			l.First->right = NULL;
		}
		delete t;
	}
}
void DelTree(TREE_TDG& t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		DelTree(t->left);
		DelTree(t->right);
		// xoa danh sach muon tra
		while (t->thedocgia.DoubleList_MuonTra.First != NULL)
		{
			DelDoubleList(t->thedocgia.DoubleList_MuonTra);
		}
		delete t;
	}
}
void DeleteMemory(TREE_TDG& t, MCONTRO& DauS)
{
	delete[]MangRandom;
	//Xoa Doc Gia
	DelTree(t);
	// Xoa Danh Muc Sach
	for (int i = 0; i < DauS.n; i++)
	{
		while (DauS.nDS[i]->List_DMS.First != NULL)
		{
			DelList(DauS.nDS[i]->List_DMS);
		}
		// Xoa Dau Sach
		delete DauS.nDS[i];
	}
}
