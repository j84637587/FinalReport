#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <ctime>
using namespace std;
int  RandomNumber(int range,int min)
{
	srand((unsigned int)time(NULL));
	int x = rand() % range + min;
	return x;
}
int  draw(vector<string>vec)//���
{
	int x = RandomNumber(vec.size(), 0);
	cout << "card " << x << "	:" << vec.at(x) << endl;
	return x; 
}

int main()
{
	/*string s = "���o"; s+="a"; cout << s << endl;
	cout<<s.find("�o", 0)<<endl;
	cout << s.find("b", 0) << endl;*/
	vector<string> card;
	int Player, Round = 5;
	cout << "�C���W�h:\nbalabalabala...\n\n";//�ɹC���W�h
	cout << "�п�J�C���H��(���3~8�H):"; cin >> Player;
	int *PlayerScore = new int[Player];//���a����(�ʺA�t�m)
	/**PlayerScore = 0;//0���}�l�p��*/
	for (int i = 0; i < Player; i++)
		PlayerScore[i] = 0;//0���}�l�p��
	map<string, int> JewelScore, Gift;
	string str; int i = -1;
	for (char ch = 'a'; ch < 'a' + 15; ch++)
	{
		string s; s += ch;//��r����r��
		str = "�_�åd" + s;//cout << str << endl;
		card.push_back(str);//��J�_�åd
		int x = RandomNumber(20, 1);/*�ü��_�åd����1~20*/
		JewelScore[str] = x; i++;
		cout << i << endl;
		if ((ch - 'a') % 3 == 0)
		{
			card.push_back("�����d"); i++;
			cout << ".."<<i << endl;
		}//��J���i�����d
	}
	for (int i = 1; i <= 3; i++)
	{//�Ǫ��d
		card.push_back("Monster a");
		card.push_back("Monster b");
		card.push_back("Monster c");
		card.push_back("Monster d");
		card.push_back("Monster e");
	}
	//�H�W���P�襤���F��
	/*int i = card.size();
	while (i--)//��P�˥�
	{
		card.erase(card.begin() + draw(card));
	}*/
	while (Round--)
	{	
		cout << "------Round" << 5 - Round << "------\n";
		bool EndOfTurn = false, *Adventure = new bool[Player];//�s�����^�X�O�_�~���I(�ʺA�t�m)
		*Adventure = true;
		int AdventureCount = Player, Jewel = 0, GiftScore = 0;//Gift�����d,�p��^�a�H�Ƥ��_������
		int *PlayerRoundScore = new int[Player];//���a�^�X����(�ʺA�t�m)
		/**PlayerRoundScore = 0;//0���}�l�p��*/
		for(int i=0;i<Player;i++)
			PlayerRoundScore[i] = 0;//0���}�l�p��
		map<string, int> Monster;//�������W�Ǫ��d�i��
		Monster["Monster a"] = 0;
		Monster["Monster b"] = 0;
		Monster["Monster c"] = 0;
		Monster["Monster d"] = 0;
		Monster["Monster e"] = 0;
		vector<string> PassagewayCard;//�q�D�W���d

		while (!EndOfTurn) //�^�X�|������
		{
			int HomeCount = 0;
			bool *end= new bool[Player];//�����^�X
			*end = false;
			string GetCard=card[draw(card)];
			PassagewayCard.push_back(GetCard);
			if (GetCard.find("�_�åd",0)<=10) { 
				Jewel += JewelScore[GetCard]; 
				cout << "�_��:" << Jewel << endl;
			}//�P�_�e�T�Ӧr���_�åd
			else if (GetCard == "�����d") { 
				Gift[GetCard] = 5; 
				GiftScore += Gift[GetCard];
				cout << "�����d:" << GiftScore << endl;
			}//�ɫe�T�i�����@�i5���A�ĥ|�B���i���@�i10��,map�g
			else{
				Monster[GetCard]++;
				cout << GetCard << "�ƶq:" << Monster[GetCard];
			}
			system("pause");
			if (Monster[GetCard] == 2) {
				/*��i�Ǫ��d�A�q�D�Y�a�A���q�D�W�Ҧ��d���A�^�X����*/
				break;
			}
			for (int i = 0; i < Player; i++)//���a�ާ@part
			{
				if(Adventure[i] == false)continue;
				else {
					int t;
					do {
						cout << "�аݪ��a" << i + 1 << "�O�_�~���I(��J1��0)";
						cin >> t;
					} while (!(t == 1 || t == 0));
					Adventure[i] = t;
					if (Adventure[i] == false) {
						HomeCount++;//�^�X�^�a�H�ƥ[�@
						AdventureCount--;//�^�X�_�I�a��@
					}
				}

			}
			cout << "�����^�a�H��:" << HomeCount <<",�~��_�I�H��:"<< AdventureCount << endl;
			if (HomeCount==1) {
				/*��o�����d�A�W�o�q�D�W�_��*/
				for (int i = 0; i < Player; i++)
				{
					//if (end[i] == true)continue;
					if (end[i] == false && Adventure[i] == false)
					{
						PlayerScore[i] += (Jewel + GiftScore);
						cout << "���a" << i + 1 << "��o�_�ۤ���:" << Jewel << ",��o�����d����:"
							<< GiftScore << ",���^�X��o����:" << PlayerScore[i] << endl;
						Jewel = 0;
						//card.erase(card.begin() + );//���������d
						end[i] = true;
						break;
					}
				}

			}
			else {
				/*�����d�d�b�q�D�W�A�����_��*/
				for (int i = 0; i < Player; i++)
				{
					if (end[i] == false && Adventure[i] == false)
					{
						PlayerScore[i] += (Jewel / HomeCount);
						cout << "���a" << i + 1 << "��o�_�ۤ���:" << Jewel / HomeCount << ",���^�X��o����:" << PlayerScore[i] << endl;
						end[i] = true;//break;
					}
					/*else {
						PlayerRoundScore[i] = (Jewel % HomeCount) / AdventureCount;//�d�b�q�D�W���_�ۥ������~���I��
						cout << "���a" << i + 1 << "�ثe�^�X��o�_�ۤ���:" << PlayerRoundScore[i] << endl;
					}*/
				}
				if (HomeCount != 0)Jewel %= HomeCount;//�d�b���W���_��
				if (AdventureCount == 0)break;
				cout << "�ثe���W�_��:" << Jewel << ",���W�_�I�a�U���o:" << Jewel / AdventureCount << "��" << endl;
			}//������:�j�a���^�a,�⧹���d���R�������D,�w�^�a�����a�������^�X�����D
		}
		

	}
	system("pause");
	return 0;
}
/*
3~8�H(�����Φ^�a)
5�^�X
5�i�����d
15�i�_�åd�P15�i�Ǫ��d(�C�ةǪ��d�U3�i)

1.	�C�쪱�a���@�����d�B�@�i��a�d�M�@�y�b�O
2.	�N�����d�H����J�U�Ӧ^�X��

1.	�C�@�^�X�}�l�e�A�N�^�X���������d�~�J�����d�襤�A�ö}�l�C���C
2.	½�}�P�襤���Ĥ@�i�d��A��߰ݨC�@�쪱�a�O�_�~���I
3.	�_�åd�A�h�N�_�åd�W���Ʀr���������C�ӿ��"����"���a�A�ѤU�_�é�b�_�åd�W�C
4.	�����d�h�N������b�q�D�W�A�b�����d�W�����(�e�T�i�����@�i5���A�ĥ|�B���i���@�i10��) �A�u���b�@���ܦ^�a�A�~�ள�������A�_�h�N�~��d�b�q�D�W�C
5.	�Ǫ��d�A�X�{�⦸�A��ܱ��I�����a�A�Ҧ��٨S���^��a���_�éM���e�S�H�a���������N�������h�A�^�X�����C
6.	��^��a�����a�i�H�����b�q�D�W���_�áA�l�ƪ��_���~���b�q�D�W�A�o�쪺�_�é��b�סA�_�è�C�����������|�����C

�C����������:1.½���i�ۦP�a��2.�Ҧ����a��^��a�C

�C�����^�X������A�̦h�_�ê����a��ӡC

*/