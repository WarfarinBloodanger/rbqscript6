#include<bits/stdc++.h>
using namespace std;
#define double long double
typedef uint32_t uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef const uchar OPCODE;
typedef vector<uchar> codeset;
OPCODE NOP=0x88;
OPCODE LOADNUM=0XA0;
OPCODE LOADSTR=0XA1;
OPCODE LOADVAR=0XA2;
OPCODE LOADVARLOCAL=0XA3;
OPCODE LOADARR=0XA4;
OPCODE LOADPARAM=0XA5;
OPCODE LOADFUNC=0XA6;
OPCODE LOADTRUE=0XA7;
OPCODE LOADFALSE=0XA8;
OPCODE LOADNULL=0XA9;
OPCODE LOADUNDEFINED=0XAA;
OPCODE LOADOBJ=0XAB;
OPCODE ASSIGNLOCAL=0XC0;
OPCODE ASSIGN=0XC1;
OPCODE OR=0XC2;
OPCODE AND=0XC3;
OPCODE BITOR=0XC4;
OPCODE BITAND=0XC5;
OPCODE XOR=0XC6;
OPCODE EQL=0XC7;
OPCODE NEQ=0XC8;
OPCODE BIG=0XC9;
OPCODE GE=0XCA;
OPCODE SML=0XCB;
OPCODE LE=0XCC;
OPCODE POSITIVE=0XCD;
OPCODE NEGATIVE=0XCE;
OPCODE ADD=0XD0;
OPCODE SUB=0XD1;
OPCODE MUL=0XD2;
OPCODE DIV=0XD3;
OPCODE MOD=0XD4;
OPCODE LSHF=0XD5;
OPCODE RSHF=0XD6;
OPCODE NOT=0XD7;
OPCODE BITNOT=0XD8;
OPCODE JUMP=0XE0;
OPCODE JUMP_IF_FALSE=0XE1;
OPCODE LOOP=0XE2;
OPCODE GETADDR=0XE3;
OPCODE CALL=0XE4;
OPCODE GETFIELD=0XE5;
OPCODE RETURN=0XE6;
OPCODE NEWFRAME=0XE7;
OPCODE DELFRAME=0XE8;
OPCODE POP=0XE9;
OPCODE LOADTHIS=0XEA;
OPCODE SEEK=0XFF;
OPCODE BREAKHOLDER=0XF0;
OPCODE CTNHOLDER=0XF1; 
char excpbuf[1024];
#define fatal(str,...) do{sprintf(excpbuf,str,__VA_ARGS__);throw (string)excpbuf;}while(0)
void output(string opname,const string&value,const string&comment){
	for(uint i=0;i<opname.size();i++)opname[i]=tolower(opname[i]); 
	printf("%16s %16s %16s\n",opname.c_str(),((value.size()>12)?value.substr(0,9)+"...":value).c_str(),comment.c_str());
}
void outputbc(uint ip,const codeset&s){
	printf("[%04d]  ",ip);
	int i=0;
	if(s.size()%9==0){
		for(auto a:s){
			printf("%02X ",a);
			if(i%9==8&&i!=s.size()-1)printf("\n        ");
			i++;
		}
		return;
	}
	for(auto a:s){
		printf("%02X ",a);
		if(i%9==8&&i!=s.size()-1)printf("\n        ");
		i++;
	}
	if(s.size()%9)while(i%9)printf("   "),i++;
}
struct bitparse{
	union{
		double x;
		uchar bits[16];
		ull n;
	};
};
struct func{
	vector<int> pid,upvs;
	codeset instr;
	int id;
};
bitparse bpser; 
char buf[24];
map<int,string>builtin;
string chkid(int id){
	return builtin[id];
}
string num2str(const double&d){
	sprintf(buf,"%.12Lg",d);return buf;
}
queue<func> funcq;
int usedfuncs=1024;
inline int newfunc(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	func f;usedfuncs++,f.id=usedfuncs,f.pid=pid,f.instr=instr,f.upvs=upvs;
	funcq.push(f);
	return usedfuncs;
}
void runbytes(const codeset&s){
	uint ip=0,oldip=0,len=s.size();
	while(ip<len){
		codeset used;
		#define addall() do{for(uint i=oldip;i<=ip;i++)used.push_back(s[i]);outputbc(oldip,used);}while(0)
		switch(s[ip]){
			default:{
				fatal("unknown bytecode %02X at position %d",s[ip],ip);
				break;
			}
			case SEEK:{
				addall();
				output("SEEK","","");
				break;
			}
			case LOADSTR:{
				string str="\'";
				ip++;
				uint id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				uint t=id;
				uchar v=0;
				while(id--)v=s[++ip]*0xfu+s[++ip],str.push_back(v);
				str+='\'';
				if(str.size()>12)str=str.substr(0,8)+"...'";
				addall();
				output("LOADSTR",str,"length="+num2str(t));
				break;
			}
			case LOADTRUE:{
				addall();
				output("LOADTRUE","","");
				break;
			}
			case LOADFALSE:{
				addall();
				output("LOADTRUE","","");
				break;
			}
			case LOADNULL:{
				addall();
				output("LOADNULL","","");
				break;
			}
			case LOADUNDEFINED:{
				addall();
				output("LOADUNDEFINED","","");
				break;
			}
			case LOADTHIS:{
				addall();
				output("LOADTHIS","","");
				break;
			}
			case LOADVAR:case LOADVARLOCAL:{
				ip++;uint oip=ip;
				uint id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output(s[oip]==LOADVAR?"LOADVAR":"LOADVARLOCAL","$"+num2str(id),chkid(id));
				break;
			}
			case ASSIGN:case ASSIGNLOCAL:{
				addall();
				output(s[ip]==ASSIGN?"ASSIGN":"ASSIGNLOCAL","","");
				break;
			}
			case LOADNUM:{
				ip++;
				bpser.bits[0]=s[ip];
				bpser.bits[1]=s[ip+1];
				bpser.bits[2]=s[ip+2];
				bpser.bits[3]=s[ip+3];
				bpser.bits[4]=s[ip+4];
				bpser.bits[5]=s[ip+5];
				bpser.bits[6]=s[ip+6];
				bpser.bits[7]=s[ip+7];
				bpser.bits[8]=s[ip+8];
				bpser.bits[9]=s[ip+9];
				bpser.bits[10]=s[ip+10];
				bpser.bits[11]=s[ip+11];
				bpser.bits[12]=s[ip+12];
				bpser.bits[13]=s[ip+13];
				bpser.bits[14]=s[ip+14];
				bpser.bits[15]=s[ip+15];
				ip+=15;
				addall();
				output("LOADNUM",num2str(bpser.x),"");
				break;
			}
			case POP:{
				addall();
				output("POP","","");
				break;
			}
			#define MATH(v,sym)\
			case v:{\
				addall();\
				output(#v,"","");\
				break;\
			}
			MATH(ADD,+);
			MATH(SUB,-);
			MATH(MUL,*);
			MATH(DIV,/);
			MATH(MOD,%);
			MATH(EQL,==);
			MATH(NEQ,!=);
			MATH(BIG,>);
			MATH(GE,>=);
			MATH(SML,<);
			MATH(LE,<=);
			MATH(BITAND,&);
			MATH(BITOR,|);
			MATH(LSHF,<<);
			MATH(RSHF,>>);
			MATH(AND,&&);
			MATH(OR,||);
			MATH(XOR,^);
			#undef MATH
			#define UNARY(v,sym)\
			case v:{\
				addall();\
				output(#v,"","");\
				break;\
			}
			UNARY(NOT,!);
			UNARY(BITNOT,~);
			UNARY(POSITIVE,+);
			UNARY(NEGATIVE,-);
			case LOADARR:{
				ip++;
				int len=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("LOADARR",num2str(len),"");
				break;
			}
			case LOADOBJ:{
				ip++;
				int len=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("LOADOBJ",num2str(len),"");
				break;
			}
			case GETADDR:{
				addall();
				output("GETADDR","","");
				break;
			}
			case LOADFUNC:{
				ip++;
				uint pcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				uint size=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				uint upvcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				uint v;vector<int> pid,upvs;codeset instr;
				while(pcnt--)pid.push_back(s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(upvcnt--)upvs.push_back(v=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(size--)instr.push_back(s[ip]),ip++;
				ip--;
				int fid=newfunc(pid,instr,upvs);
				addall();
				output("LOADFUNC","","set to <"+num2str(fid)+">");
				break;
			}
			case CALL:{
				ip++;
				uint argscnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("CALL",num2str(argscnt),"");
				break;
			}
			case RETURN:{
				addall();
				output("RETURN","","");
				break;
			}
			case JUMP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3; 
				addall();
				output("JUMP",num2str(offset),"jump to "+num2str(ip+offset+1));
				break;
			}
			case JUMP_IF_FALSE:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("JUMP_IF_FALSE",num2str(offset),"jump to "+num2str(ip+offset+1));
				break;
			}
			case LOOP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("LOOP",num2str(offset),"loop to "+num2str(ip-1-offset+1-3));
				break;
			}
			case NEWFRAME:{
				addall();
				output("NEWFRAME","","");
				break;
			}
			case DELFRAME:{
				addall();
				output("DELFRAME","","");
				break;
			}
		}
		oldip=++ip;
	}
}
void seekcode(const func&f){
	cout<<"\nfunction <function "<<f.id<<">"<<endl;
	cout<<"  arguments:";
	for(auto a:f.pid)cout<<a<<' ';
	cout<<endl;
	cout<<"  upvalues:";
	for(auto a:f.upvs)cout<<a<<' ';
	cout<<endl;
	runbytes(f.instr);
}
void initvm(){
	int r=0;
	usedfuncs=1024;
}
void see(string arg){
	codeset s;
	ifstream fcin(arg,ios::binary);
	char c;while(fcin.get(c))s.push_back((uchar)c);
	int id=newfunc(vector<int>(),s,vector<int>());
	while(!funcq.empty())seekcode(funcq.front()),funcq.pop();fcin.close();
}
int main(int argc,char **argv){
	try{	
		if(argc<=1)exit(puts("Usage: rbqup <file1> <file2>...")&&1);
		initvm();
		int v=1;for(;v<argc;v++){
			printf("\n--- File '%s' ---",argv[v]);
			usedfuncs=1024,see(argv[v]);
		} 
	}
	catch(string&s){
		cout<<s<<endl;
	}
}
