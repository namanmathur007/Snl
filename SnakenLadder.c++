#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

void board();
int roll();
void check_location(int &p, int &cm, int s1, int s2, int s3, int l1, int l2, int l3);
void check_progress(int x, int y);

char player[100];
char computer[100];
string snakes[2000];
	
int main(){
	srand(time(NULL));
	
	for(int i = 1; i <= 100; i++){ // Initially giving all position of P and C empty i.e ' ' .
		player[i] = ' ';
		computer[i] = ' ';  
	}
	for(int i = 1; i <= 100;i++){ // Initially giving all snakes and ladders value double space i.e "  " .
		snakes[i] = "  ";
	}
	
	// Generating random snakes and ladders position for every new match
	int s1 = rand()%(98)+12;
	int s2 = rand()%(88)+6;
	int s3 = rand()%(77)+2;
	
	int l1 = rand()%(89)+4;
	int l2 = rand()%(79)+3;
	int l3 = rand()%(69)+2;
	int p = 0;
	
	// Checking if Snake and ladder do not come at same place
	while(s1 == l1 && s1 == l2 && s1 == l3 && s2 == l1 && s2 == l2 && s2 == l3 && s3 == l1 && s3 == l2 && s3 == l3){
	int s1 = rand()%(98)+4;
	int s2 = rand()%(88)+3;
	int s3 = rand()%(77)+2;
	
	int l1 = rand()%(89)+4;
	int l2 = rand()%(79)+3;
	int l3 = rand()%(69)+2;
	}	
		
	snakes[s1] = "S1";
	snakes[s2] = "S2";
	snakes[s3] = "S3";
	snakes[l1] = "L1";
	snakes[l2] = "L2";
	snakes[l3] = "L3";
	board();
	char n;
	int r;
	int c;
	int cm=0;
	while(p != 100 || cm!= 100){
		player[p] = ' ';
		computer[cm] = ' ';
		cout << "Press r to roll dice : ";
		cin >> n;
		if(n == 'r'){
			if(p > 100)
				p = p;
			else{
				r = roll();
				p = p + r;
				if(p > 100){
					p = p - r;
				}
				cout << "Player(P) got " << r << endl;
				if(r == 6){
					
					r = roll();
					p = p + r;
					if(p > 100){
					p = p - r;
				}
					cout << "Player(P) got " << r << "at 2nd turn"<< endl;
					if(r == 6){
						
						r = roll();
						p = p + r;
						if(p > 100 && r != 6){
							p = p - r;
						}
						if(r == 6){
							p = 6 - 6 - 6;
							cout << "Three consecutive 6's which is 0" << endl;
						}
						else
							cout << "Player(P) got " << r << "at 3rd turn"<< endl;
					}
				}
			}
		}
		
		if(n == 'r' ){
			if(cm > 100)
				cm = cm;
			else{
				r = roll();
				cm = cm + r;
				if(cm > 100){
					cm = cm - r;
				}
				cout << "Computer(C) got " << r << endl;
				if(r == 6){
					
					r = roll();
					cm = cm + r;
					if(cm > 100){
						cm = cm - r;
					}
					cout << "Computer(C) got " << r << endl;
					if(r == 6){
						r = roll();
						cm = cm + r;
						cout << "Computer(C) got " << r << endl;
						if(cm > 100 && r != 6){
							cm = cm - r;
						}
						if(r == 6){
							cm = 6 - 6 - 6;
							cout << "Three consecutive 6's equal to 0" << endl;
						}
					}
				}
			}
		}	
		
		
		
		
		player[p] = 'P';
		computer[cm] = 'C';
		board();
		check_location(p,cm,s1,s2,s3,l1,l2,l3);
			
		if(p == 100 && cm == 100)
			cout << "DRAW!!!";
		else if(p == 100){
			cout << "Player Has Won!!!";
			break;
		}
		else if(cm == 100){
			cout << "Computer has Won!!!";
			break;
		}
	}
}

void board(){
	cout << " ______________________________________________________________________" << endl;
	cout << "|  " << "100  " << "|  " << "99  " << "|  " << "98  "  << "|  " << "97  " << "|  " << "96  " << "|  " << "95  " << "|  " << "94  " << "|  " << "93  " << "|  " << "92  " << "|  " << "91  |" <<endl;
	cout << "|" << snakes[100] << " " <<  player[100] << computer[100]  << "  |" << snakes[99] << " " <<  player[99] << computer[99]  << " |" << snakes[98] << " " <<  player[98] << computer[98]  << " |" << snakes[97] << " " <<  player[97] << computer[97]  << " |" << snakes[96] << " " <<  player[96] << computer[96]  << " |" << snakes[95] << " " <<  player[95] << computer[95] << " |" << snakes[94] << " " <<  player[94] << computer[94]<< " |" << snakes[93] << " " <<  player[93] << computer[93]<< " |" << snakes[92] << " " <<  player[92] << computer[92] << " |" << snakes[91] << " " <<  player[91] << computer[91] << " |"; 
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "81   " << "|  " << "82  " << "|  " << "83  "  << "|  " << "84  " << "|  " << "85  " << "|  " << "86  " << "|  " << "87  " << "|  " << "88  " << "|  " << "89  " << "|  " << "90  |" <<endl;
	cout << "|" << snakes[81] << " " <<  player[81] << computer[81]  << "  |" << snakes[82] << " " <<  player[82] << computer[82]  << " |" << snakes[83] << " " <<  player[83] << computer[83]  << " |" << snakes[84] << " " <<  player[84] << computer[84]  << " |" << snakes[85] << " " <<  player[85] << computer[85]  << " |" << snakes[86] << " " <<  player[86] << computer[86] << " |" << snakes[87] << " " <<  player[87] << computer[87]<< " |" << snakes[88] << " " <<  player[88] << computer[88]<< " |" << snakes[89] << " " <<  player[89] << computer[89] << " |" << snakes[90] << " " <<  player[90] << computer[90] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "80   " << "|  " << "79  " << "|  " << "78  "  << "|  " << "77  " << "|  " << "76  " << "|  " << "75  " << "|  " << "74  " << "|  " << "73  " << "|  " << "72  " << "|  " << "71  |" <<endl;
	cout << "|" << snakes[80] << " " <<  player[80] << computer[80]  << "  |" << snakes[79] << " " <<  player[79] << computer[79]  << " |" << snakes[78] << " " <<  player[78] << computer[78]  << " |" << snakes[77] << " " <<  player[77] << computer[77]  << " |" << snakes[76] << " " <<  player[76] << computer[76]  << " |" << snakes[75] << " " <<  player[75] << computer[75] << " |" << snakes[74] << " " <<  player[74] << computer[74]<< " |" << snakes[73] << " " <<  player[73] << computer[73]<< " |" << snakes[72] << " " <<  player[72] << computer[72] << " |" << snakes[71] << " " <<  player[71] << computer[71] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "61   " << "|  " << "62  " << "|  " << "63  "  << "|  " << "64  " << "|  " << "65  " << "|  " << "66  " << "|  " << "67  " << "|  " << "68  " << "|  " << "69  " << "|  " << "70  |" <<endl;
	cout << "|" << snakes[61] << " " <<  player[61] << computer[61]  << "  |" << snakes[62] << " " <<  player[62] << computer[62]  << " |" << snakes[63] << " " <<  player[63] << computer[63]  << " |" << snakes[64] << " " <<  player[64] << computer[64]  << " |" << snakes[65] << " " <<  player[65] << computer[65]  << " |" << snakes[66] << " " <<  player[66] << computer[66] << " |" << snakes[67] << " " <<  player[67] << computer[67]<< " |" << snakes[68] << " " <<  player[68] << computer[68]<< " |" << snakes[69] << " " <<  player[69] << computer[69] << " |" << snakes[70] << " " <<  player[70] << computer[70] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "60   " << "|  " << "59  " << "|  " << "58  "  << "|  " << "57  " << "|  " << "56  " << "|  " << "55  " << "|  " << "54  " << "|  " << "53  " << "|  " << "52  " << "|  " << "51  |" <<endl;
	cout << "|" << snakes[60] << " " <<  player[60] << computer[60]  << "  |" << snakes[59] << " " <<  player[59] << computer[59]  << " |" << snakes[58] << " " <<  player[58] << computer[58]  << " |" << snakes[57] << " " <<  player[57] << computer[57]  << " |" << snakes[56] << " " <<  player[56] << computer[56]  << " |" << snakes[55] << " " <<  player[55] << computer[55] << " |" << snakes[54] << " " <<  player[54] << computer[54]<< " |" << snakes[53] << " " <<  player[53] << computer[53]<< " |" << snakes[52] << " " <<  player[52] << computer[52] << " |" << snakes[51] << " " <<  player[51] << computer[51] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "41   " << "|  " << "42  " << "|  " << "43  "  << "|  " << "44  " << "|  " << "45  " << "|  " << "46  " << "|  " << "47  " << "|  " << "48  " << "|  " << "49  " << "|  " << "50  |" <<endl;
	cout << "|" << snakes[41] << " " <<  player[41] << computer[41]  << "  |" << snakes[42] << " " <<  player[42] << computer[42]  << " |" << snakes[43] << " " <<  player[43] << computer[43]  << " |" << snakes[44] << " " <<  player[44] << computer[44]  << " |" << snakes[45] << " " <<  player[45] << computer[45]  << " |" << snakes[46] << " " <<  player[46] << computer[46] << " |" << snakes[47] << " " <<  player[47] << computer[47]<< " |" << snakes[48] << " " <<  player[48] << computer[48]<< " |" << snakes[49] << " " <<  player[49] << computer[49] << " |" << snakes[50] << " " <<  player[50] << computer[50] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "40   " << "|  " << "39  " << "|  " << "38  "  << "|  " << "37  " << "|  " << "36  " << "|  " << "35  " << "|  " << "34  " << "|  " << "33  " << "|  " << "32  " << "|  " << "31  |" <<endl;
	cout << "|" << snakes[40] << " " <<  player[40] << computer[40]  << "  |" << snakes[39] << " " <<  player[39] << computer[39]  << " |" << snakes[38] << " " <<  player[38] << computer[38]  << " |" << snakes[37] << " " <<  player[37] << computer[37]  << " |" << snakes[36] << " " <<  player[36] << computer[36]  << " |" << snakes[35] << " " <<  player[35] << computer[35] << " |" << snakes[34] << " " <<  player[34] << computer[34]<< " |" << snakes[33] << " " <<  player[33] << computer[33]<< " |" << snakes[32] << " " <<  player[32] << computer[32] << " |" << snakes[31] << " " <<  player[31] << computer[31] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "21   " << "|  " << "22  " << "|  " << "23  "  << "|  " << "24  " << "|  " << "25  " << "|  " << "26  " << "|  " << "27  " << "|  " << "28  " << "|  " << "29  " << "|  " << "30  |" <<endl;
	cout << "|" << snakes[21] << " " <<  player[21] << computer[21]  << "  |" << snakes[22] << " " <<  player[22] << computer[22]  << " |" << snakes[23] << " " <<  player[23] << computer[23]  << " |" << snakes[24] << " " <<  player[24] << computer[24]  << " |" << snakes[25] << " " <<  player[25] << computer[25]  << " |" << snakes[26] << " " <<  player[26] << computer[26] << " |" << snakes[27] << " " <<  player[27] << computer[27]<< " |" << snakes[28] << " " <<  player[28] << computer[28]<< " |" << snakes[29] << " " <<  player[29] << computer[29] << " |" << snakes[30] << " " <<  player[30] << computer[30] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "20   " << "|  " << "19  " << "|  " << "18  "  << "|  " << "17  " << "|  " << "16  " << "|  " << "15  " << "|  " << "14  " << "|  " << "13  " << "|  " << "12  " << "|  " << "11  |" <<endl;
	cout << "|" << snakes[20] << " " <<  player[20] << computer[20]  << "  |" << snakes[19] << " " <<  player[19] << computer[19]  << " |" << snakes[18] << " " <<  player[18] << computer[18]  << " |" << snakes[17] << " " <<  player[17] << computer[17]  << " |" << snakes[16] << " " <<  player[16] << computer[16]  << " |" << snakes[15] << " " <<  player[15] << computer[15] << " |" << snakes[14] << " " <<  player[14] << computer[14]<< " |" << snakes[13] << " " <<  player[13] << computer[13]<< " |" << snakes[12] << " " <<  player[12] << computer[12] << " |" << snakes[11] << " " <<  player[11] << computer[11] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	cout << "|  " << "1    " << "|  " << "2   " << "|  " << "3   "  << "|  " << "4   " << "|  " << "5   " << "|  " << "6   " << "|  " << "7   " << "|  " << "8   " << "|  " << "9   " << "|  " << "10  |" <<endl;
	cout << "|" << snakes[1] << " " <<  player[1] << computer[1]  << "  |" << snakes[2] << " " <<  player[2] << computer[2]  << " |" << snakes[3] << " " <<  player[3] << computer[3]  << " |" << snakes[4] << " " <<  player[4] << computer[4]  << " |" << snakes[5] << " " <<  player[5] << computer[5]  << " |" << snakes[6] << " " <<  player[6] << computer[6] << " |" << snakes[7] << " " <<  player[7] << computer[7]<< " |" << snakes[8] << " " <<  player[8] << computer[8]<< " |" << snakes[9] << " " <<  player[9] << computer[9] << " |" << snakes[10] << " " <<  player[10] << computer[10] << " |";
	cout << endl << " ----------------------------------------------------------------------" << endl;
	
}
int roll(){
	int p;
	p = rand()%(6)+1;
	return p;
}
void check_location(int &p, int &cm, int s1, int s2, int s3, int  l1, int  l2, int l3){
	int flag = 0;
	int t,tc;
	if(p == s1){
		t = p;
		p = p - 5;
		if(p < 0){
			p = 0;
		}
		cout << "Player(P) got into Snake!! at "<< t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	else if(p == s2){
		t = p;
		p = p - 9;
		if(p < 0){
			p = 0;
		}
		cout << "Player(P) got into Snake!! at "<< t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	else if(p == s3){
		t = p;
		p = p - 13;
		if(p < 0){
			p = 0;
		}
		cout << "Player(P) got into Snake!! at "<< t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	if(cm == s1){
		tc = cm;
		cm = cm - 5;
		if(cm < 0){
			cm = 0;
		}
		cout << "Computer(C) got into Snake!! at "<< tc << " you are moved to place" << cm << endl;
		flag = 1;
	}
	else if(cm == s2){
		tc = cm;
		cm = cm - 9;
		if(cm < 0){
			cm = 0;
		}
		cout << "Computer(C) got into Snake!! at "<< tc << "  you are moved to place" << cm << endl;
		flag = 1;
	}
	else if(cm == s3){
		tc = cm;
		cm = cm - 13;
		if(cm < 0){
			cm = 0;
		}
		cout << "Computer(C) got into Snake!! at "<< tc << "  you are moved to place" << cm << endl;
		flag = 1;
	}
	
	
	if(p == l1){
		t = p;
		p = p + 4;
		cout << "Player(P) got into LADDER!! at " << t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	else if(p == l2){
		t = p;
		p = p + 8;
		cout << "Player(P) got into LADDER!! at " << t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	else if(p == l3){
		t = p;
		p = p + 12;
		cout << "Player(P) got into LADDER!! at " << t << " you are moved to place" << p<< endl;
		flag = 1;
	}
	
	if(cm == l1){
		tc = cm;
		cm = cm + 4;
		cout << "Computer() got into LADDER!! at " << tc << " you are moved to place" << cm<< endl;
		flag = 1;
	}
	else if(cm == l2){
		tc = cm;
		cm = cm + 8;
		cout << "Computer(C) got into LADDER!! at " << tc << " you are moved to place" << cm<< endl;
		flag = 1;
	}
	else if(cm == l3){
		tc = cm;
		cm = cm + 12;
		cout << "Computer(C) got into LADDER!! at " << tc << " you are moved to place" << cm<< endl;
		flag = 1;
	}
	
	if(flag == 1){
		player[p] = 'P';
		computer[cm] = 'C';
		player[t] = ' ';
		computer[tc] = ' ';
		board();
	}
}


##Copyrighht Naman##
