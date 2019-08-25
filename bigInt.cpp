//Author Shanu Gandhi 25 Aug 2019
#include <bits/stdc++.h>
using namespace std;

bool lessthan(string str1, string str2);
bool greaterthan(string str1, string str2);
bool equals(string str1, string str2);

string removefrontzero(string str);
string add(string str1, string str2);
string diff(string str1, string str2);
string divide(string str1, string str2);
string multiplysingle(string str1, string str2);
string multiplymultiple(string str1, string str2);
string percentile(string str1,string str2);

string gcd(string str1, string str2) ;
string factorial(string str);
string fastpow(string str, string str2);
string percentile(string str1,string str2);




bool lessthan(string str1, string str2){
	str1=removefrontzero(str1);
	str2=removefrontzero(str2);
	int len1=str1.length(), len2= str2.length();
	if(len1<len2) return true;
	if(len1>len2) return false;
	for(int i =0; i< len1 ; i++){
		if(str1[i]<str2[i]) return true;
		if(str1[i]>str2[i]) return false;
	}
	return false;
}
bool greaterthan(string str1, string str2){
	str1=removefrontzero(str1);
	str2=removefrontzero(str2);
	int len1=str1.length(), len2= str2.length();
	if(len1>len2) return true;
	if(len1<len2) return false;
	for(int i =0; i< len1 ; i++){
		if(str1[i]>str2[i]) return true;
		if(str1[i]<str2[i]) return false;
	}
	return false;
}
bool equals(string str1, string str2){
	str1=removefrontzero(str1);
	str2=removefrontzero(str2);
	int len1=str1.length(), len2= str2.length();
	if(len1!=len2) return false;
	for(int i =0; i< len1 ; i++){
		if(str1[i]!=str2[i]) return false;
	}
	return true;
}

string add(string str1, string str2){
	int len1=str1.length(),len2=str2.length(),maxlen,carry =0,sum=0;
	maxlen = max(len1,len2);
	vector <char> str3;
	for(int i =0;i<maxlen+1;i++){
		if(i!=maxlen){
			if( (len1-1-i) >=0 && (len2-1-i)>=0){
				sum=int(str1[len1-1-i])+int(str2[len2-1-i])-96+carry;
				//cout<<"case1 "<<sum<<endl;
				if(sum>=10){
					str3.push_back(sum%10+48); carry=1;
					//cout<<"if 1str3"<<str3[i]<<endl;
				}
				else{
					str3.push_back(sum+48); carry=0;
					//cout<<"else 1str3"<<str3[i]<<endl;
				}
			}
			if( (len1-1-i) >=0 && (len2-1-i)<0){
				sum=int(str1[len1-1-i])-48+carry;
				//cout<<"case2 "<<sum<<endl;
				if(sum>=10){
					str3.push_back(sum%10+48); carry=1;
					//cout<<"if 2str3"<<str3[i]<<endl;
				}
				else{
					str3.push_back(sum+48); carry=0;
					//cout<<"else 2 str3"<<str3[i]<<endl;
				}
			}
			if( (len1-1-i) <0 && (len2-1-i) >= 0){
				sum=int(str2[len2-1-i])-48+carry;
				//cout<<"case3 "<<sum<<endl;
				if(sum>=10){
					str3.push_back(sum%10+48); carry=1;
					//cout<<"if 3 str3"<<str3[i]<<endl;
				}
				else{
					str3.push_back(sum+48); carry=0;
					//cout<<"else 3 str3"<<str3[i]<<endl;
				}	
			}
		}
		if(i==maxlen & carry ==1){
			str3.push_back('1');
		}
	}
	string str4;
	//cout<<"str3 \n"<<endl;
	for(int i =0;i<str3.size();i++){
		//cout<<str3[i]<<"!";
		str4.push_back(str3[str3.size()-i-1]);
	}
	return str4;
}


string diff(string str1, string str2){
	//vector <char> vstr3;
	bool str2_zer0=true;
	for(int i =0;i<str2.length();i++){
		if(str2[i]!='0'){ str2_zer0 = false; break;}
	}
	if(str2_zer0 == true) return str1;

	string str3,str4,str5;
	int diffrence,len1=str1.length(),len2=str2.length();
	bool allzero=true;
	for(int i =0; i <str2.length();i++){
		diffrence = 9- (int(str2[i])-48);
		//cout<<" "<<diffrence;
		if(diffrence!=9){ allzero=false;}
		str3.push_back(diffrence+48);
	}
	if(!allzero){
		str4=add(str3,"1");
	}
	else{
		str4=str3;
	}
	if(str4.length()==str1.length()){
		str4=add(str1,str4);
		if(str4.length()!=str1.length()){
		   str4=&str4[1];
		}
	}else{
		int diff2=len1-str4.length();
		for(int i =0; i<diff2; i++) str5.push_back('9');
		for(int i =0; i<str4.length(); i++) str5.push_back(str4[i]);
			str4=str5;
		str4=add(str1,str4);
		   str4=&str4[1];
	}
	return removefrontzero(str4);
}

string removefrontzero(string str){
	int count =0;
	for(int i =0; i <str.length();i++){
		if(str[i]!='0') break;
		else count++;
	}
	if(count==str.length()){
		str="0";
	}else{
		str= &str[count];
	}
	return str;
}
string multiplysingle(string str1, string str2){
	string str3,str4;
	int x,y,
		carry=0,
		z=int(str2[0])-48,
		len=str1.length();
	if(z==0) return "0";
	for(int i =0; i<len; i++){
		y=int(str1[len-1-i])-48;
		x=(y*z)+carry;
		//cout<<"y :"<<y<<"x :"<<x<<endl;
		if(x>=10){carry=x/10;str3.push_back((x%10)+48);}
		else{ carry=0;str3.push_back(x+48);}
	}
	//cout<<"carry :"<<carry<<endl;
	if(carry!=0) str3.push_back(carry+48);
	//strrev(str3);
	int str3len=str3.length();
	for(int i=0; i<str3len; i++) str4.push_back(str3[str3len-i-1]);
	return str4;
}
string multiplymultiple(string str1 , string str2){
	if(str2.length()==1) return multiplysingle(str1,str2);

	string str3,str4,result,product,sum="0",multipliee;
	int strlen1=str1.length(), strlen2=str2.length(),itr=0;
	if(strlen1<strlen2){str3=str1;str1=str2;str2=str3;}
	strlen1=str1.length(), strlen2=str2.length();
	for(int i =0; i<strlen2; i++){
		multipliee=str2[strlen2-1-i];
		product=multiplysingle(str1,multipliee);
		for(int i =0; i<itr; i++) {
			product.push_back('0');
		}
		sum=add(product,sum);
		itr++;
	}
	return sum;
}

string factorial(string str){
	string prod="1";
	while(str!="0"){
		prod=multiplymultiple(prod,str);
		str=diff(str,"1");
		removefrontzero(str);
	}
	return prod;
}
//string division(string str1, string str2){
//	string str_i="0",divsr=str2,str3;
	//cout<<"funct call"<<endl;
	//cout<<"bef while"<< lessthan(str1,divsr)<<endl;
//	while(greaterthan(str1,divsr)){
		//cout<<"in while"<<endl;
	//	divsr=multiplymultiple(str2,str_i);
		//cout<<"divsr"<<divsr<<endl;
		//str_i=add(str_i,"1");
		//cout<<"stri"<<str_i<<endl;
//	}
//return str_i;
//}

string gcd(string str1, string str2) {
	str1=removefrontzero(str1);
	str2=removefrontzero(str2); 
	if(str1=="0") return str2;
	return gcd(percentile(str2,str1),str1);
   // if (str1 == "0" ) return str2;
   // if (str2 == "0")  return str1;
   // else if ( equals(str1,str2)) 
   //    return str1; 
   // else if (greaterthan(str1 ,str2)) 
   //    return gcd( divide(str1,str2), str2); 
   // else return gcd(str1, divide(str2, str1)); 
}

string divide(string str1, string str2){
	string str5;
	str1=removefrontzero(str1);
	str2=removefrontzero(str2);
	if(str2=="0") return "Divide by Zero Exception";
	if(str2=="1") return str1;
	if(lessthan(str1,str2)) return "0";
	else{
		string muls[11];
		string str3;
		for(int i =0; i<=10; i++){
			if(i==0) str3="0";
			else if(i==1) str3="1";
			else if(i==2) str3="2";
			else if(i==3) str3="3";
			else if(i==4) str3="4";
			else if(i==5) str3="5";
			else if(i==6) str3="6";
			else if(i==7) str3="7";
			else if(i==8) str3="8";
			else if(i==9) str3="9";
			else if(i==10) str3="10";
			muls[i]=multiplymultiple(str2,str3);
		}

		int x=0,j,count=0; string str4,str6,str7,strdiff="";
		bool leftrem=false;
		while(x<str1.length()){
			//cout<<"here";
			if(leftrem==true){
				str4=strdiff+str1[x];
			}else{
				str4=str1[x];
			}
			if(lessthan(str4, str2)){
				j=x+1;count=0;
				while(lessthan(str4, str2) && (x+count)<str1.length()){
					str5.push_back(48);
					str4.push_back(str1[j]); 
					j=j+1;
					count=count+1;;
				}
				if(lessthan(str4, str2)){
					//cout<<"remainder: "<<str4<<endl;
					break;
				}
			}
			//cout<<str4<<endl;
			//cout<<"x: "<<x<<"count :"<<count<<endl;
			x= x+count+1;
			count=0;
			int i;
			bool equalflag=false;
			for(i =0; i<=10;i++){
				if(equals(str4,muls[i]))
				  {//cout<<"equal\n"; 
					equalflag=true; break;}
				
				if(lessthan(str4,muls[i]))
				  {//cout<<"greater\n"; 
					equalflag=false; break;}
			
			}

			if(equalflag==true){
				str5.push_back(i+48);
				leftrem=false;
			}
			else{
				leftrem =true;
				strdiff="";
				strdiff= diff(str4,muls[i-1]);
				//cout<<"\ndiff "<<strdiff<<endl<<endl;
				//str6.push_back(diff());
				str5.push_back(i+48-1);
				//cout<<"x: "<<x<<"strlen "<<str1.length()<<endl;
			}
		}

	}
	return removefrontzero(str5);
}
string percentile(string str1,string str2){
	str1=removefrontzero(str1);
	str2=removefrontzero(str2);
	string str3,str4,str5,str6;
	str3=divide(str1,str2);
	str4=multiplymultiple(str3,str2);
	str5=diff(str1,str4);
	return str5;

}
string fastpow(string str1, string str2){
	string str3, str4, str5;
	if(str2=="0") return "1";
	if(str2=="1") return str1;
	str3= fastpow(str1, divide(str2,"2"));
	if(percentile(str2,"2")=="0")
		return multiplymultiple(str3,str3);
	return multiplymultiple(str1,multiplymultiple(str3,str3));
}

int main()
{
	long long T,x;
	string str1,str2,str3,str4;
	cin>>T;
	for(long long c=0 ; c<T; c++){
		cin>>x;
		if(x==1){
			cin>>str1;
		    cin>>str2;
		    str1=removefrontzero(str1);
		    str2=removefrontzero(str2);
		    cout<<fastpow(str1,str2)<<endl;
		}
		if(x==2){
			cin>>str1;
		    cin>>str2;
		    str1=removefrontzero(str1);
		    str2=removefrontzero(str2);
		    cout<<gcd(str1,str2)<<endl;
		}
		if(x==3){
			cin>>str1;
    		str1=removefrontzero(str1);
    		cout<<factorial(str1)<<endl;
		}

	}
	
    // cin>>str1;
    // cin>>str2;
    // str1=removefrontzero(str1);
    // str2=removefrontzero(str2);
   // str3=divide(str1, str2);//divide
    //cout<<"Divide is: "<<str3<<endl;

    //cout<<"Percentile is: "<<percentile(str1,str2)<<endl;//percenrile    
    
    //bool isequal=lessthan(str1,str2);
    //cout<<"\nlessthan :"<<isequal<<endl;
    // str3=add(str1,str2);
    // cout<<"sum is :"<<str3<<endl;
    // str3=diff(str1,str2);
    // cout<<"minus is :"<<str3<<endl;
    // str4=removefrontzero(str1);
    // cout<<"remove zero is :"<<str4<<endl;
    // str3=multiplymultiple(str1,str2);
    // cout<<"mul is :"<<str3<<endl;
//    cout<<"a/b "<<division(str1,str2);
    //cout<<"a less tha b "<<lessthan(str1,str2);
  //  cout<<"GCD is :"<<gcd(str1,str2)<<endl;//gcd

//    cout<<"Fastpow is :"<<fastpow(str1,str2)<<endl;//fastpow
  //  auto finish = std::chrono::high_resolution_clock::now();
  //  std::chrono::duration<double> elapsed = finish - start;
   // std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}
