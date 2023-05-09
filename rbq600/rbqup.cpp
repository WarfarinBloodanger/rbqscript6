#include<bits/stdc++.h>
using namespace std;
typedef double DB;
#define double long double
typedef uint32_t uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef const uchar OPCODE;
typedef vector<uchar> codeset;
vector<string> str_pool;
vector<double> num_pool;

OPCODE NOP=0x00;
OPCODE LOAD0=0x10;
OPCODE LOAD1=0x11;
OPCODE LOAD2=0x12;
OPCODE LOAD3=0x13;
OPCODE LOAD4=0x14;
OPCODE LOAD5=0x15;
OPCODE LOAD6=0x16;
OPCODE LOAD7=0x17;
OPCODE LOAD8=0x18;
OPCODE LOAD9=0x19;
OPCODE LOAD10=0x1A;
OPCODE LOAD11=0x1B;
OPCODE LOAD12=0x1C;
OPCODE LOAD13=0x1D;
OPCODE LOAD14=0x1E;
OPCODE LOAD15=0x1F;
OPCODE LOAD1BIT=0x21;
OPCODE LOAD2BIT=0x22;
OPCODE LOAD3BIT=0x23;
OPCODE LOAD4BIT=0x24;
OPCODE LOCALVAR1B=0X90;
OPCODE LOCALVAR2B=0X91;
OPCODE LOCALVAR3B=0X92;
OPCODE NUMSLOT1B=0X93;
OPCODE NUMSLOT2B=0X94;
OPCODE NUMSLOT3B=0X95;
OPCODE NUMSLOT=0XEF;
OPCODE STRSLOT1B=0X96;
OPCODE STRSLOT2B=0X97;
OPCODE STRSLOT3B=0X98;
OPCODE CALL1B=0X99;
OPCODE CALL2B=0X9A;
OPCODE CALL3B=0X9B;
OPCODE FUNCSLOT1B=0X9C;
OPCODE FUNCSLOT2B=0X9D;
OPCODE FUNCSLOT3B=0X9E;
OPCODE FUNCSLOT=0X9F;
OPCODE LOOP3B=0X81;
OPCODE CONSTRUCT1B=0X82;
OPCODE CONSTRUCT2B=0X83;
OPCODE CONSTRUCT3B=0X84;
OPCODE AND1B=0X85;
OPCODE AND2B=0X86;
OPCODE AND3B=0X87;
OPCODE OR1B=0X88;
OPCODE OR2B=0X89;
OPCODE OR3B=0X8A;
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
OPCODE LOADLONGNUM=0XAC;
OPCODE STRSLOT=0XAD;
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
OPCODE ADDE=0XB0;
OPCODE SUBE=0XB1;
OPCODE MULE=0XB2;
OPCODE DIVE=0XB3;
OPCODE MODE=0XB4;
OPCODE LSHFE=0XB5;
OPCODE RSHFE=0XB6;
OPCODE BITORE=0XB7;
OPCODE BITANDE=0XB8;
OPCODE XORE=0XB9;
OPCODE ADD=0XD0;
OPCODE SUB=0XD1;
OPCODE MUL=0XD2;
OPCODE DIV=0XD3;
OPCODE MOD=0XD4;
OPCODE LSHF=0XD5;
OPCODE RSHF=0XD6;
OPCODE NOT=0XD7;
OPCODE BITNOT=0XD8;
OPCODE HAS=0XD9;
OPCODE TYPEOF=0XDA;
OPCODE CHOOSE=0XDB;
OPCODE ISA=0XDC;
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
OPCODE MAKECLASS=0XEB;
OPCODE CONSTRUCT=0XEC;
OPCODE CHECKTYPE=0xED;
OPCODE LOADSUPER=0xEE;
OPCODE SEEK=0XFF;
OPCODE BREAKHOLDER=0XF0;
OPCODE CTNHOLDER=0XF1;
OPCODE EXTENDACC=0XF2;
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
int force_short_double;
struct bitparse{
	union{
		double x;
		uchar bits[16];
		ull n;
	};
};
struct bitparse8{
	union{
		DB x;
		uchar bits[8];
		ull n;
	};
};
struct func{
	vector<int> pid,upvs;
	codeset instr;
	string id;
};
char buf[24];
string num2str(const double&d){
	sprintf(buf,"%.12Lg",d);return buf;
}
vector<func> func_pool;
inline uint func_slot(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	func_pool.push_back((func){pid,upvs,instr,"_constant_pool_slot_"+num2str(func_pool.size())});
	return func_pool.size()-1;
}
bitparse bpser; 
bitparse8 bpser8; 
map<int,string>builtin;
string chkid(int id){
	return builtin[id];
}
queue<func> funcq;
int usedfuncs=1024;
inline int newfunc(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	func f;usedfuncs++,f.id=num2str(usedfuncs),f.pid=pid,f.instr=instr,f.upvs=upvs;
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
				addall();
				output("<UNKNOWN>","","");
				break;
			}
			#define loader(x)\
			case LOAD##x:{\
				addall();\
				output("LOADNUM_"#x,""#x,"");\
				break;\
			}
			loader(0) loader(1) loader(2) loader(3) 
			loader(4) loader(5) loader(6) loader(7) 
			loader(8) loader(9) loader(10) loader(11) 
			loader(12) loader(13) loader(14) loader(15)
			case LOAD1BIT:case LOAD2BIT:case LOAD3BIT:case LOAD4BIT:{
				uint v=s[ip]-0x20,t=0,z=0;
				while(t<v)z=z*256+s[++ip],t++;
				addall();
				output("LOAD"+num2str(v)+"BIT",num2str(z),"");
				break;
			}
			#undef loader
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
				while(id--)v=s[ip+1]*0xfu+s[ip+2],ip+=2,str.push_back(v);
				str+='\'';
				if(str.size()>12)str=str.substr(0,8)+"...'";
				addall();
				output("LOADSTR",str,"length="+num2str(t));
				break;
			}
			case STRSLOT:case STRSLOT1B:case STRSLOT2B:case STRSLOT3B:{
				uchar a=s[ip++];
				uint id;string t;
				switch(a){
					case STRSLOT1B:id=s[ip],t="STRSLOT1B";break;
					case STRSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1,t="STRSLOT2B";break;
					case STRSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2,t="STRSLOT3B";break;
					case STRSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3,t="STRSLOT";break;
				}
				string str=str_pool[id];
				addall();
				output(t,"'"+str+"'","length="+num2str(str.size()));
				break;
			}
			case NUMSLOT:case NUMSLOT1B:case NUMSLOT2B:case NUMSLOT3B:{
				uchar a=s[ip++];
				uint id;string t;
				switch(a){
					case NUMSLOT1B:id=s[ip],t="NUMSLOT1B";break;
					case NUMSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1,t="NUMSLOT2B";break;
					case NUMSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2,t="NUMSLOT3B";break;
					case NUMSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3,t="NUMSLOT";break;
				}
				addall();
				output(t,num2str(num_pool[id]),"");
				break;
			}
			case FUNCSLOT1B:case FUNCSLOT2B:case FUNCSLOT3B:case FUNCSLOT:{
				uchar a=s[ip++];
				uint id;string t;
				switch(a){
					case FUNCSLOT1B:id=s[ip],t="FUNCSLOT1B";break;
					case FUNCSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1,t="FUNCSLOT2B";break;
					case FUNCSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2,t="FUNCSLOT3B";break;
					case FUNCSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3,t="FUNCSLOT";break;
				}
				addall();
				output(t,num2str(id),"size="+num2str(func_pool[id].instr.size()));
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
			case LOADSUPER:{
				addall();
				output("LOADSUPER","","");
				break;
			}
			
			#define multi(A,b,c,d)\
			case A:case b:case c:case d:{\
				uchar a=s[ip++];\
				uint id;string t;\
				switch(a){\
					case A:id=s[ip],t=#A;break;\
					case b:id=s[ip]*0xff+s[ip+1],ip+=1,t=#b;break;\
					case c:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2,t=#c;break;\
					case d:case LOADVARLOCAL:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3,t=#d;break;\
				}\
				addall();\
				output(t,num2str(id),"");\
				break;\
			}
			case LOADVAR:case LOADVARLOCAL:case LOCALVAR1B:case LOCALVAR2B:case LOCALVAR3B:{
				uchar a=s[ip++];
				uint id;string t;
				switch(a){
					case LOCALVAR1B:id=s[ip],t="LOCALVAR1B";break;
					case LOCALVAR2B:id=s[ip]*0xff+s[ip+1],ip+=1,t="LOCALVAR2B";break;
					case LOCALVAR3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2,t="LOCALVAR3B";break;
					case LOADVAR:case LOADVARLOCAL:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3,t=a==LOADVAR?"LOADVAR":"LOADLOCALVAR";break;
				}
				addall();
				output(t,num2str(id),"");
				break;
			}
			case ASSIGN:case ASSIGNLOCAL:{
				addall();
				output(s[ip]==ASSIGN?"ASSIGN":"ASSIGNLOCAL","","");
				break;
			}
			case LOADNUM:{
				ip++;
				bpser8.bits[0]=s[ip];
				bpser8.bits[1]=s[ip+1];
				bpser8.bits[2]=s[ip+2];
				bpser8.bits[3]=s[ip+3];
				bpser8.bits[4]=s[ip+4];
				bpser8.bits[5]=s[ip+5];
				bpser8.bits[6]=s[ip+6];
				bpser8.bits[7]=s[ip+7];
				ip+=7;
				addall();
				output("LOADNUM",num2str(bpser.x),"");
				break;
			}
			case LOADLONGNUM:{
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
				output("LOADLONGNUM",num2str(bpser.x),"");
				break;
			}
			case POP:{
				addall();
				output("POP","","");
				break;
			}
			#define assigner(tokname,t)\
			case tokname:{\
				addall();\
				output(#tokname,"","");\
				break;\
			}
			assigner(ADDE,+)
			assigner(SUBE,-)
			assigner(MULE,*)
			assigner(DIVE,/)
			assigner(MODE,%)
			assigner(XORE,^)
			assigner(BITANDE,&)
			assigner(BITORE,|)
			assigner(LSHFE,<<)
			assigner(RSHFE,>>)
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
			MATH(XOR,^);
			multi(AND1B,AND2B,AND3B,AND)
			multi(OR1B,OR2B,OR3B,OR)
			MATH(HAS,?)
			MATH(CHOOSE,?)
			MATH(ISA,?)
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
			multi(CALL1B,CALL2B,CALL3B,CALL)
			case JUMP:{
				ip++;
				uint f=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("JUMP",num2str(f),"to "+num2str(ip+4+f));
				break;
			}
			case JUMP_IF_FALSE:{
				ip++;
				uint f=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("JUMP_IF_FALSE",num2str(f),"to "+num2str(ip+4+f));
				break;
			}
			case LOOP:{
				ip++;
				uint f=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("LOOP",num2str(f),"to "+num2str(ip-f));
				break;
			}
			case RETURN:{
				addall();
				output("RETURN","","");
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
			case MAKECLASS:{
				ip++;
				uint fieldcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				addall();
				output("MAKECLASS",num2str(fieldcnt),num2str(fieldcnt)+" field"+(fieldcnt==1?"":"s"));
				if(ip+1<s.size()&&s[ip+1]==EXTENDACC){
					used.clear(),oldip=++ip;
					while(fieldcnt--)++ip;
					addall();
					output("EXTENDACC","","");
				}
				break;
			}
			multi(CONSTRUCT1B,CONSTRUCT2B,CONSTRUCT3B,CONSTRUCT)
			case CHECKTYPE:{
				ip++;
				uint argnum=s[ip]*0xff+s[ip+1];
				ip++;
				addall();
				output("CHECKTYPE",num2str(argnum),"check arg "+num2str(argnum));
				break;
			}
			case EXTENDACC:{
				addall();
				output("EXTENDACC","","");
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
	usedfuncs=1024;
}
int version_number;
inline int read2b(ifstream&fcin){int g=fcin.get()*0xff;g+=fcin.get();return g;}
inline int read4b(ifstream&fcin){int g=fcin.get()*0xffffff;g+=fcin.get()*0xffff;g+=fcin.get()*0xff;g+=fcin.get();return g;}
int nxtf=0,fulstr=0;
inline string int2str(int x,int base){
	string r="";int n=0;
	if(x==0)return (string)"0";
	if(x<0)n=1,x=-x;
	while(x){
		int v=x%base;
		if(v<0)v-=base,x+=base;
		if(v>=0&&v<=9)r=r+char('0'+v);
		else r=r+char('A'+v-10);
		x/=base;
	}
	reverse(r.begin(),r.end());
	if(n)r="-"+r;
	return r;
}
inline string strictstr(const string&str){
	string r="";
	for(auto a:str){
		switch(a){
			case '\a':r+="\\a";break;
			case '\t':r+="\\t";break;
			case '\n':r+="\\n";break;
			case '\r':r+="\\r";break;
			case '\b':r+="\\b";break;
			case '\\':r+="\\\\";break;
			case '"':r+="\"";break;
			default:{
				if(!isprint(a))r+="\\u00"+int2str(int(a),16);
				else r+=a;
				break;
			}
		}
	}
	return r;
}
void see(string arg){
	codeset s;
	ifstream fcin(arg,ios::binary);
	char c;
	if(fcin.get(c)&&c==0x0f){
		if(!(fcin.get(c)&&(unsigned char)c==0xf0))fatal("uncompatible bytecode file '%s'",arg.c_str());
		if(!(fcin.get(c)&&c==0x26))fatal("uncompatible bytecode file '%s'",arg.c_str());
		if(!(fcin.get(c)&&c==0x56))fatal("uncompatible bytecode file '%s'",arg.c_str());
		version_number=read4b(fcin),force_short_double=fcin.get(); 
		int g;
		g=read4b(fcin);
		if(force_short_double)while(g--){for(int i=0;i<8;i++)bpser8.bits[i]=fcin.get();num_pool.push_back(bpser8.x);}
		else while(g--){for(int i=0;i<16;i++)bpser.bits[i]=fcin.get();num_pool.push_back(bpser.x);}
		g=read4b(fcin);
		while(g--){
			int r=read4b(fcin);string v="";
			while(r--)v+=fcin.get();str_pool.push_back(strictstr(v));
		}
		g=read4b(fcin);
		while(g--){
			int pidlen=read2b(fcin),instrlen=read4b(fcin),upvslen=read2b(fcin);
			vector<int>pid,upvs;codeset instr;
			while(pidlen--)pid.push_back(read2b(fcin));
			while(instrlen--)instr.push_back(fcin.get());
			while(upvslen--)upvs.push_back(read2b(fcin));
			func_slot(pid,instr,upvs);
		}
	}
	else s.push_back(uchar(c)); 
	while(fcin.get(c))s.push_back((uchar)c);
	newfunc(vector<int>(),s,vector<int>());
	cout<<"Version Number: "<<version_number<<endl;
	if(nxtf){
		cout<<"String Constant Pool ( size="<<str_pool.size()<<" )"<<endl;
		int t=0;
		for(auto a:str_pool)if(fulstr)printf("[%04d]    '%s'\n",t++,a.c_str()); else printf("[%04d]    '%s'\n",t++,(a.size()<=20?a:a.substr(0,17)+"...").c_str());
		cout<<"\nNumber Constant Pool ( size="<<num_pool.size()<<" )"<<endl;
		t=0;
		for(auto a:num_pool)printf("[%04d]    %.12Lg\n",t++,a);
	}
	while(!funcq.empty())seekcode(funcq.front()),funcq.pop();
	for(auto a:func_pool)seekcode(a);
	fcin.close();
}
int main(int argc,char **argv){
	try{	
		if(argc<=1)exit(puts("Usage: rbqup <file1> <file2>...")&&1);
		initvm();
		int v=1;for(;v<argc;v++){
			if(strlen(argv[v])>=2&&argv[v][0]=='-'&&argv[v][1]=='f')(strlen(argv[v])>=3&&argv[v][2]=='f')?fulstr=nxtf=1:nxtf=1;
			else{
				printf("\n--- File '%s' ---",argv[v]);
				usedfuncs=1024,see(argv[v]),nxtf=0;
			}
		} 
	}
	catch(string&s){
		cout<<s<<endl;
	}
}
