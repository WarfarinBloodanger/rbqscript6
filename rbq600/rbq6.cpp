#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef int64_t ull;
typedef uint32_t uint;
typedef unsigned char uchar;
typedef const uchar OPCODE;
struct hasher{
	size_t operator()(const uint&x)const{return x;}
};
const string HELP = "See [https://github.com/WarfarinBloodanger/rbqscript6].";
const string COPYRIGHT = "See [https://github.com/WarfarinBloodanger/rbqscript6].";
const string CREDITS = "See [https://github.com/WarfarinBloodanger/rbqscript6].";
const string LICENSE = "See [https://github.com/WarfarinBloodanger/rbqscript6]. GNU 3.0 License is used.";
#define umap cc_hash_table
typedef double DB;
#define double long double

const int CURRENT_VERSION=6;
int force_short_double=0;
int version_number;

OPCODE NOP=0x0F;
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
typedef vector<uchar> codeset;
enum {
	TOK_NUM,TOK_STR,TOK_ID,TOK_HEX,
	TOK_ADD,TOK_SUB,
	TOK_MUL,TOK_DIV,TOK_MOD,
	TOK_EQL,TOK_NEQ,TOK_BIG,TOK_SML,TOK_GE,TOK_LE,
	TOK_AND,TOK_OR,TOK_NOT,
	TOK_BITAND,TOK_BITOR,TOK_BITNOT,TOK_XOR,TOK_LSHF,TOK_RSHF,
	TOK_COM,TOK_ASS,TOK_DOT,TOK_QUEZ,TOK_COL,
	TOK_LPR,TOK_RPR,TOK_LBK,TOK_RBK,TOK_LBR,TOK_RBR,TOK_FEN,
	TOK_FUNC,TOK_IF,TOK_ELSE,TOK_WHILE,TOK_RET,TOK_FOR,TOK_VAR,TOK_BREAK,TOK_CTN,TOK_ALL,
	TOK_TRUE,TOK_FALSE,TOK_NULL,TOK_UNDEFINED,TOK_INCLUDE,TOK_THIS,TOK_CLASS,TOK_NEW,TOK_HAS,TOK_TYPEOF,TOK_CHOOSE,TOK_IS,
	TOK_OP,TOK_CONSTRUCTOR,TOK_PUB,TOK_PROT,TOK_PRIV,TOK_SUPER,
	TOK_ADDE,TOK_SUBE,
	TOK_MULE,TOK_DIVE,TOK_MODE,
	TOK_BITANDE,TOK_BITORE,TOK_XORE,TOK_LSHFE,TOK_RSHFE,TOK_ARW,
};
const char* tokenname[]={
	"number","string","identifier","hexnumber",
	"'+'","'-'","'*'","'/'","'%'","'=='","'!='","'>'","'<'","'>='","'<='",
	"'&&'","'||'","'!'","'&'","'|'","'~'","'^'","'<<'","'>>'",
	"','","'='","'.'","'?'","':'","'('","')'","'['","']'","'{'","'}'","';'",
	"'function'","'if'","'else'","'while'","'return'","'for'","'var'","'break'","'continue'","'all'",
	"'true'","'false'","'null'","'undefined'","'include'","'this'","'class'","'new'","'has'","'typeof'","'or'","'is'",
	"'operator'","'constructor'","'public'","'protected'","'private'","'super'",
	"+=","-=",
	"*=","/=","%=",
	"&=","|=","^=","<<=",">>=","->"
};
inline int prior(char tok){
	switch(tok){
		case TOK_COM:return 10;
		case TOK_ASS:
		case TOK_ADDE:case TOK_SUBE:case TOK_MULE:case TOK_DIVE:case TOK_MODE:
		case TOK_BITANDE:case TOK_BITORE:case TOK_XORE:case TOK_LSHFE:case TOK_RSHFE:return 20;
		case TOK_CHOOSE:return 24;
		case TOK_QUEZ:return 25;
		case TOK_OR:return 30;
		case TOK_AND:return 40;
		case TOK_BITOR:return 50;
		case TOK_XOR:return 60;
		case TOK_BITAND:return 70;
		case TOK_EQL:case TOK_NEQ:return 80;
		case TOK_LE:case TOK_SML:case TOK_GE:case TOK_BIG:case TOK_HAS:case TOK_TYPEOF:case TOK_IS:return 90;
		case TOK_LSHF:case TOK_RSHF:return 100;
		case TOK_ADD:case TOK_SUB:return 110;
		case TOK_MUL:case TOK_DIV:case TOK_MOD:return 120;
		case TOK_NOT:case TOK_BITNOT:return 130;
		case TOK_LPR:case TOK_LBK:case TOK_DOT:case TOK_ARW:return 140; 
		default:return 1;
	}
}
struct token{
	char type;
	int line,column;
	string val;
};
vector<token> toks;
char getidtype(const string&s){
	if(s=="function")return TOK_FUNC;
	if(s=="if")return TOK_IF;
	if(s=="else")return TOK_ELSE;
	if(s=="while")return TOK_WHILE;
	if(s=="for")return TOK_FOR;
	if(s=="return")return TOK_RET;
	if(s=="var")return TOK_VAR;
	if(s=="break")return TOK_BREAK;
	if(s=="continue")return TOK_CTN;
	if(s=="all")return TOK_ALL;
	if(s=="true")return TOK_TRUE;
	if(s=="false")return TOK_FALSE;
	if(s=="null")return TOK_NULL;
	if(s=="undefined")return TOK_UNDEFINED;
	if(s=="include")return TOK_INCLUDE;
	if(s=="this")return TOK_THIS;
	if(s=="class")return TOK_CLASS;
	if(s=="new")return TOK_NEW;
	if(s=="has")return TOK_HAS;
	if(s=="typeof")return TOK_TYPEOF;
	if(s=="or")return TOK_CHOOSE;
	if(s=="is")return TOK_IS;
	if(s=="operator")return TOK_OP;
	if(s=="constructor")return TOK_CONSTRUCTOR;
	if(s=="public")return TOK_PUB;
	if(s=="protected")return TOK_PROT;
	if(s=="private")return TOK_PRIV;
	if(s=="super")return TOK_SUPER;
	return TOK_ID; 
}
void tokenize(char *src,int strict=1){
	uint line=1,column=1;
	#define chkln (line+=src[loc]=='\n',column=src[loc]=='\n'?1:column+1)
	uint len=strlen(src);
	uint loc=0;
	while(loc<len){
		token cur;cur.line=line,cur.column=column;
		if(isalpha(src[loc])||src[loc]=='_'){
			while((loc<len)&&(isalpha(src[loc])||isdigit(src[loc])||src[loc]=='_'))cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			cur.type=getidtype(cur.val),toks.push_back(cur); 
		}
		else if(isdigit(src[loc])||src[loc]=='.'){
			bool d=0,e=0,n=0;
			if(src[loc]=='0'&&loc+1<len&&(src[loc+1]=='x'||src[loc+1]=='X')){
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				while((loc<len&&isdigit(src[loc]))||(src[loc]>='a'&&src[loc]<='f')||(src[loc]>='A'&&src[loc]<='F'))cur.val.push_back(tolower(src[loc])),(chkln,loc++,loc-1);
				cur.type=TOK_HEX,toks.push_back(cur);
			}
			else{
				while((loc<len&&isdigit(src[loc]))||src[loc]=='.'||src[loc]=='E'||src[loc]=='e'||src[loc]=='-'){
					if(src[loc]=='.'){if(!d)d=1;else break;}
					if(src[loc]=='e'||src[loc]=='E'){if(n&&!e)e=1;else break;}
					if(src[loc]=='-'){if(loc-1>=0&&(src[loc-1]=='e'||src[loc-1]=='E'));else break;}
					if(isdigit(src[loc]))n=1;
					cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				}
				if(cur.val.size()==1&&cur.val[0]=='.')cur.type=TOK_DOT;
				else cur.type=TOK_NUM;
				toks.push_back(cur);
			}
		}
		else if(src[loc]=='\''||src[loc]=='\"'){
			if(loc+2<len&&src[loc+1]==src[loc]&&src[loc+2]==src[loc]){
				char e=src[loc];
				loc+=2;
				while(loc+2<len&&!(src[loc]==e&&src[loc+1]==e&&src[loc+2]==e)){
					if(src[loc]=='\\')cur.val.push_back('\\');
					cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				}
				if(strict&&loc+2>=len)fatal("uncompleted multi-line string, expected '%c%c%c' at end",e,e,e);
				if(src[loc]==e)cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				loc+=2;
				cur.type=TOK_STR,toks.push_back(cur);
			}
			else{
				char s=src[loc];cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				while(loc<len&&src[loc]!=s&&src[loc]!='\r'&&src[loc]!='\n'){
					if(src[loc]=='\\')cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
					cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				}
				if(src[loc]==s)cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				cur.type=TOK_STR,toks.push_back(cur);
			}
		}
		else if(src[loc]=='`'){
			char s=src[loc];cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			while(loc<len&&src[loc]!=s&&src[loc]!='\r'&&src[loc]!='\n'){
				if(src[loc]=='\\')cur.val.push_back('\\');
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			}
			if(src[loc]==s)cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			cur.type=TOK_STR,toks.push_back(cur);
		}
		else if(isspace(src[loc]))(chkln,loc++,loc-1);
		#define checkeql_(tokname)\
			if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_##tokname##E;
		#define checkeql(tokname)\
		{\
			cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_##tokname;\
			checkeql_(tokname);\
			toks.push_back(cur);\
			break;\
		}
		else switch(src[loc]){
			case('+'):checkeql(ADD);
			case('-'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='>')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_ARW;
				else if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_SUBE;
				else cur.type=TOK_SUB;
				toks.push_back(cur);
				break;
			}
			case('*'):checkeql(MUL);
			case('/'):{
				if(loc+1<len&&src[loc+1]=='/'){
					loc++;
					while(loc<len&&src[loc]!='\n')loc++;
					loc++;
				}
				else if(loc+1<len&&src[loc+1]=='*'){
					loc++;
					while(loc+1<len&&!(src[loc]=='*'&&src[loc+1]=='/'))loc++;
					if(loc+1>=len)fatal("uncompleted comment symbol, expected '*/' at end%c",' ');
					loc+=2;
				}
				else checkeql(DIV);
				break;
			}
			case('%'):checkeql(MOD);
			case('.'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_DOT,toks.push_back(cur);break;
			case('('):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LPR,toks.push_back(cur);break;
			case('['):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LBK,toks.push_back(cur);break;
			case('{'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LBR,toks.push_back(cur);break;
			case(')'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RPR,toks.push_back(cur);break;
			case(']'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RBK,toks.push_back(cur);break;
			case('}'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RBR,toks.push_back(cur);break;
			case('^'):checkeql(XOR);
			case(';'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_FEN,toks.push_back(cur);break;
			case(','):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_COM,toks.push_back(cur);break;
			case(':'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_COL,toks.push_back(cur);break;
			case('?'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_QUEZ,toks.push_back(cur);break;
			case('='):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_EQL;
				else cur.type=TOK_ASS;
				toks.push_back(cur);
				break;
			}
			case('>'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_GE;
				else if(loc<len&&src[loc]=='>'){
					cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RSHF;
					checkeql_(RSHF);
				}
				else cur.type=TOK_BIG;
				toks.push_back(cur);
				break;
			}
			case('<'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LE;
				else if(loc<len&&src[loc]=='<'){
					cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LSHF;
					checkeql_(LSHF);
				}
				else cur.type=TOK_SML;
				toks.push_back(cur);
				break;
			}
			case('!'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_NEQ;
				else cur.type=TOK_NOT;
				toks.push_back(cur);
				break;
			}
			case('&'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='&')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_AND;
				else{
					cur.type=TOK_BITAND;
					checkeql_(BITAND);
				}
				toks.push_back(cur);
				break;
			}
			case('|'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='|')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_OR;
				else{
					cur.type=TOK_BITOR;
					checkeql_(BITOR);
				}
				toks.push_back(cur);
				break;
			}
			default:if(!strict)break;fatal("unknown char '%c' at line %d, column %d",src[loc],line,column);(chkln,loc++,loc-1);break;
		}
	}
}
uint curtok;
#define tok toks[curtok]
inline void nexttok(){
	if(curtok==toks.size())fatal("expected token at the end of file%c",' ');
	curtok++;
}
token readtok(char type){
	if(curtok>toks.size()||toks[curtok].type!=type)fatal("expected token %s at line %d, column %d",tokenname[(uint)type],toks[curtok].line,toks[curtok].column);
	return toks[curtok++];
}
vector<string> str_pool;
umap<string,uint> strcid;
int used_spid;
inline uint str_slot(const string&s){
	if(strcid.find(s)==strcid.end())str_pool.push_back(s),strcid[s]=used_spid++;
	return strcid[s];
}
vector<double> num_pool;
umap<double,uint> numcid;
int used_dpid;
inline int num_slot(const double&s){
	if(numcid.find(s)==numcid.end())num_pool.push_back(s),numcid[s]=used_dpid++;
	return numcid[s];
}
struct funcslot{
	vector<int>pid;
	codeset instr;
	vector<int>upvs;
};
vector<funcslot> func_pool;
inline uint func_slot(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	func_pool.push_back((funcslot){pid,instr,upvs});
	return func_pool.size()-1;
}
umap<uint,string,hasher>names;
vector<umap<string,uint>> scopes;
vector<uint> namecnt;
vector<set<uint>> used_upvalues;
uint usedname;
inline void new_scope(){scopes.push_back(umap<string,uint>()),namecnt.push_back(0),used_upvalues.push_back(set<uint>());}
inline void del_scope(){scopes.pop_back(),namecnt.pop_back(),used_upvalues.pop_back();}
inline uint getid(const string&s,int lcl=0){
	if(!lcl)for(int i=scopes.size()-1;i>=0;i--)if(scopes[i].find(s)!=scopes[i].end()){
		for(int j=scopes.size()-1;j>i;j--)used_upvalues[j].insert(scopes[i][s]);
		return scopes[i][s];
	}
	return names[usedname+1]=s,scopes[scopes.size()-1][s]=++usedname;
}
struct bitparse8{
	union{
		DB x;
		uchar bits[8];
		ull n;
	};
};
struct bitparse{
	union{
		double x;
		uchar bits[16];
		ull n;
	};
};
bitparse bpser;
bitparse8 bpser8;
long long hex2dec(const string&s){
	long long x=0,v=0;
	uint i=0;
	if(s.size()&&s[0]=='-')v=1;
	if(s.size()<=(uint)(2+v)||(s[i]!='0'&&toupper(s[i+1]!='X')))fatal("invalid hex number: '%s'",s.c_str());
	else i+=2;
	for(;i<s.size();i++){
		if(!isdigit(s[i])&&(toupper(s[i])<'A'||toupper(s[i])>'F'))fatal("invalid hex number: '%s'",s.c_str());
		x=(x<<4)^(isdigit(s[i])?s[i]&15:10+(toupper(s[i])-'A'));
	}
	return x*(v?-1:1);
}
string dec2hex(ull x){
	string s="";int n=0;
	if(x==0)return "0x0";
	if(x<0)n=1,x=-x;
	while(x){
		int v=x&15;
		if(v<10)s+=char(v^'0');
		else s+=char(v-10+'a');
		x>>=4;
	}
	reverse(s.begin(),s.end());
	s="0x"+s;
	if(n)s="-"+s;
	return s;
}
double str2num(const string&s){
	double v;stringstream ss("");ss<<s;ss>>v;return v;
}
char buf[48];
string num2str(const double&d){
	sprintf(buf,"%.14Lg",d);return buf;
}
inline void concat(codeset &a,const codeset &b){
	for(auto x:b)a.push_back(x);
} 
bool isint(double x){
	return abs(round(x)-x)<(double)0.000000000000001;
}
inline codeset loadshort(int v){ 
	codeset s;s.push_back(v/0xffu),s.push_back(v%0xffu);return s;
} 
inline codeset loadint(int v){
	codeset s;concat(s,loadshort(v/0xffffu)),concat(s,loadshort(v%0xffffu));return s;
}
bool check_smlint(double x,codeset&s){
	if(x<0||!isint(x))return 0;
	x=uint(x);
	if(x<16)return s.push_back(LOAD0+x),1;
	if(x<=0xffffffffu){
		codeset e;
		while(x)e.push_back(uint(x)%256),x=(uint)x/256;
		reverse(e.begin(),e.end());
		return s.push_back(LOAD1BIT+e.size()-1),concat(s,e),1;
	}
	return 0;
}
codeset simple(const vector<uchar>&chosing,int id){
	codeset r,s,g=loadint(id);
	if(id==0)s.push_back(0);
	else{
		uint i=0;
		for(i=0;i<4;i++)if(g[i])break;
		for(i;i<4;i++)s.push_back(g[i]);
	}
	r.push_back(chosing[s.size()-1]),concat(r,s);
	return r;
}
inline codeset compile_localvar(int id){return simple({LOCALVAR1B,LOCALVAR2B,LOCALVAR3B,LOADVARLOCAL},id);}
inline codeset compile_var(int id){return simple({LOCALVAR1B,LOCALVAR2B,LOCALVAR3B,LOADVARLOCAL},id);}
inline codeset compile_call(int id){return simple({CALL1B,CALL2B,CALL3B,CALL},id);}
inline codeset compile_jump(int id){codeset r;r.push_back(JUMP),concat(r,loadint(id));return r;}
inline codeset compile_loop(int id){codeset r;r.push_back(LOOP),concat(r,loadint(id));return r;}
inline codeset compile_jif(int id){codeset r;r.push_back(JUMP_IF_FALSE),concat(r,loadint(id));return r;;}
inline codeset compile_and(int id){return simple({AND1B,AND2B,AND3B,AND},id);}
inline codeset compile_or(int id){return simple({OR1B,OR2B,OR3B,OR},id);}
inline codeset compile_constant(int id){return simple({STRSLOT1B,STRSLOT2B,STRSLOT3B,STRSLOT},id);}
inline codeset compile_loadfunc(int id){return simple({FUNCSLOT1B,FUNCSLOT2B,FUNCSLOT3B,FUNCSLOT},id);}
inline codeset compile_loadnum(int id){return simple({NUMSLOT1B,NUMSLOT2B,NUMSLOT3B,NUMSLOT},id);}
codeset compile_num(double x){
	codeset s;
	if(check_smlint(x,s))return s;
	return compile_loadnum(num_slot(x));
}
long long hex2dec(const string&s);
string encd(ull v){
	string s="";
	if(v<0)fatal("invalid codepoint %lld",v);
	if(v<=0x7f)s+=(char)(v&0x7f);
	else if(v<=0x7ff)s+=(char)(0xc0|((v&0x7c0)>>6)),s+=char((0x80|(v&0x3f)));
	else if(v<=0xffff)s+=char(0xe0|((v&0xf000)>>12)),s+=char(0x80|((v&0xfc0)>>6)),s+=char(0x80|(v&0x3f));
	else if(v<=0x10ffff)s+=char(0xf0|((v&0x1c0000)>>18)),s+=char(0x80|((v&0x3f00)>>12)),s+=char(0x80|((v&0xfc0)>>6)),s+=char(0x80|(v&0x3f));
	else fatal("invalid codepoint %lld",v);
	return s;
}
inline string strexpr(const string&x){
	uint len=x.size();string r="";
	#define gen(v) r+=(v)
	for(uint i=0;i<len;i++)if(x[i]=='\\'){
		if(i+1<len){
			switch(x[i+1]){
				case 'a':gen('\a');break;
				case 'n':gen('\n');break;
				case 't':gen('\t');break;
				case 'r':gen('\r');break;
				case 'b':gen('\b');break;
				case '\\':gen('\\');break;
				case '\'':gen('\'');break;
				case '\"':gen('\"');break;
				case '0':gen('\0');break;
				case 'u':{
					i+=2;
					if(i+3>=len)fatal("uncompleted unicode escape sequence in string '%s'",x.c_str());
					string e=encd(hex2dec((string)"0x"+x[i]+x[i+1]+x[i+2]+x[i+3]));
					r+=e;
					i+=2;
					break;
				}
				default:fatal("unknown escaped char '\\%c' in string '%s'",x[i+1],x.c_str());
			}
			i++;
		}
	}else gen(x[i]);
	return r;
}
inline codeset compile_str(const string&x){return compile_constant(str_slot(strexpr(x.substr(1,x.size()-2))));}
inline codeset checktype(int num,const string&type){
	codeset s;
	if(type!="any")s=compile_str(type),s.push_back(CHECKTYPE),concat(s,loadshort(num));
	return s;
}
codeset compile();
codeset compile_new();
codeset compile_block(bool a=1);
codeset compile_upvalue(string);
codeset compile_lambda();
codeset parse_args(char,uint&);
vector<int> get_used_upvalue();
vector<int> parse_params(uint&,codeset&,char ender=TOK_RPR);
codeset parse_decl();
codeset parse_obj();
int anfunc=0;
inline string anonyfunc(){return "$"+num2str(++anfunc);}
codeset parse_expr(int precd){
	codeset s,b1,b2,pc;uint tmp;bool liter=precd==prior(TOK_DOT)&&(curtok-1>=0&&(toks[curtok-1].type==TOK_DOT));
	switch(tok.type){
		case TOK_FEN:nexttok();return s; 
		#define chklit(t,str,byte)\
		case t:{\
			if(liter)concat(s,compile_str(#str)),readtok(t),s.push_back(GETADDR);\
			else readtok(t),s.push_back(byte);\
			break;\
		}
		#define chklit_strict(t,str)\
		case t:{\
			if(liter)concat(s,compile_str(#str)),readtok(t),s.push_back(GETADDR);\
			else fatal("unexpected %s at line %d, column %d, expected a property name",tokenname[(uint)tok.type],tok.line,tok.column);\
			break;\
		}
		chklit(TOK_TRUE,"true",LOADTRUE);
		chklit(TOK_FALSE,"false",LOADFALSE);
		chklit(TOK_NULL,"null",LOADNULL);
		chklit(TOK_UNDEFINED,"undefined",LOADUNDEFINED);
		chklit(TOK_THIS,"this",LOADTHIS);
		chklit(TOK_SUPER,"super",LOADSUPER);
		chklit_strict(TOK_IF,"if");
		chklit_strict(TOK_ELSE,"else");
		chklit_strict(TOK_WHILE,"while");
		chklit_strict(TOK_RET,"return");
		chklit_strict(TOK_FOR,"for");
		chklit_strict(TOK_BREAK,"break");
		chklit_strict(TOK_CTN,"continue");
		chklit_strict(TOK_INCLUDE,"include");
		chklit_strict(TOK_CLASS,"class");
		chklit_strict(TOK_HAS,"has");
		chklit_strict(TOK_CHOOSE,"or");
		chklit_strict(TOK_IS,"is");
		chklit_strict(TOK_ALL,"all");
		chklit_strict(TOK_OP,"operator");
		chklit_strict(TOK_CONSTRUCTOR,"constructor");
		chklit_strict(TOK_PUB,"public");
		chklit_strict(TOK_PROT,"protected");
		chklit_strict(TOK_PRIV,"private");
		case TOK_VAR:{
			if(liter)concat(s,compile_str("var")),readtok(TOK_VAR),s.push_back(GETADDR);
			else fatal("'var' should not appear at line %d, column %d",tok.line,tok.column);
			break;
		}
		case TOK_NEW:{
			if(liter)concat(s,compile_str("new")),readtok(TOK_VAR),s.push_back(GETADDR);
			else concat(s,compile_new());break;
			break;
		}
		case TOK_ID:{
			if(liter)concat(s,compile_str('"'+tok.val+'"')),readtok(TOK_ID),s.push_back(GETADDR);
			else concat(s,compile_var(getid(tok.val))),readtok(TOK_ID);
			break;
		}
		case TOK_TYPEOF:{
			if(liter)concat(s,compile_str('"'+tok.val+'"')),readtok(TOK_TYPEOF),s.push_back(GETADDR);
			else readtok(TOK_TYPEOF);concat(s,parse_expr(90));s.push_back(TYPEOF);break;
			break;
		}
		case TOK_NUM:concat(s,compile_num(str2num(tok.val)));readtok(TOK_NUM);break;
		case TOK_HEX:concat(s,compile_num(hex2dec(tok.val)));readtok(TOK_HEX);break;
		case TOK_STR:concat(s,compile_str(tok.val));readtok(TOK_STR);break;
		case TOK_LPR:readtok(TOK_LPR);concat(s,parse_expr(0));readtok(TOK_RPR);break;
		case TOK_LBK:readtok(TOK_LBK);concat(s,parse_args(TOK_RBK,tmp));readtok(TOK_RBK);
					s.push_back(LOADARR);concat(s,loadint(tmp));break;
		case TOK_LBR:readtok(TOK_LBR);concat(s,parse_obj());readtok(TOK_RBR);break;
		case TOK_NOT:readtok(TOK_NOT);concat(s,parse_expr(prior(TOK_NOT)));s.push_back(NOT);break;
		case TOK_BITNOT:readtok(TOK_BITNOT);concat(s,parse_expr(prior(TOK_BITNOT)));s.push_back(BITNOT);break;
		case TOK_ADD:readtok(TOK_ADD);concat(s,parse_expr(130));s.push_back(POSITIVE);break;
		case TOK_SUB:readtok(TOK_SUB);concat(s,parse_expr(130));s.push_back(NEGATIVE);break;
		case TOK_SML:concat(s,compile_lambda());break;
		case TOK_FUNC:{
			if(liter)concat(s,compile_str("function")),readtok(TOK_FUNC),s.push_back(GETADDR);
			else{
				readtok(TOK_FUNC);
				new_scope();
				readtok(TOK_LPR);vector<int> b1=parse_params(tmp,pc);readtok(TOK_RPR);
				readtok(TOK_LBR);concat(b2,pc),concat(b2,compile_block(0));readtok(TOK_RBR);
				b2.push_back(LOADUNDEFINED),b2.push_back(RETURN);
				// b2 -> instr
				// used_upvalues[used_upvalues.size()-1] -> upvs
				// b1 -> pid
				uint slot_id=func_slot(b1,b2,get_used_upvalue());
				del_scope();
				concat(s,compile_loadfunc(slot_id));
				s.push_back(ASSIGN);
			}
			break;
		}
		default:fatal("unexpected %s at line %d, column %d, expected an expression",tokenname[(uint)tok.type],tok.line,tok.column);
	}
	#define PF(code) v=tok.val,pr=prior(tok.type);curtok++;concat(s,parse_expr(pr));s.push_back(code);break
	while(curtok<toks.size()&&prior(tok.type)>precd){
		int pr;string v;
		switch(tok.type){
			case TOK_ASS:PF(ASSIGN);
			case TOK_ADDE:PF(ADDE);
			case TOK_SUBE:PF(SUBE);
			case TOK_MULE:PF(MULE);
			case TOK_DIVE:PF(DIVE);
			case TOK_MODE:PF(MODE);
			case TOK_XORE:PF(XORE);
			case TOK_LSHFE:PF(LSHFE);
			case TOK_RSHFE:PF(RSHFE);
			case TOK_BITANDE:PF(BITANDE);
			case TOK_BITORE:PF(BITORE);
			case TOK_CHOOSE:PF(CHOOSE);
			case TOK_IS:{
				v=tok.val,pr=prior(tok.type);curtok++;
				concat(s,compile_str("'"+tok.val+"'"));curtok++;s.push_back(ISA);
				break;
			}
			case TOK_QUEZ:{
				readtok(TOK_QUEZ);
				b1=parse_expr(prior(TOK_QUEZ));
				readtok(TOK_COL);
				b2=parse_expr(prior(TOK_QUEZ));
				concat(s,compile_jif(b1.size()+5));
				concat(s,b1);
				concat(s,compile_jump(b2.size()));
				concat(s,b2);
				break;
			}
			case TOK_OR:{
				v=tok.val,pr=prior(tok.type);curtok++;
				b1=parse_expr(pr); 
				concat(s,compile_or(b1.size()));
				concat(s,b1);
				break;
			}
			case TOK_AND:{
				v=tok.val,pr=prior(tok.type);curtok++;
				b1=parse_expr(pr); 
				concat(s,compile_and(b1.size()));
				concat(s,b1);
				break;
			}
			case TOK_BITOR:PF(BITOR);
			case TOK_BITAND:PF(BITAND);
			case TOK_XOR:PF(XOR);
			case TOK_EQL:PF(EQL);
			case TOK_NEQ:PF(NEQ);
			case TOK_HAS:PF(HAS);
			case TOK_BIG:PF(BIG);
			case TOK_GE:PF(GE);
			case TOK_SML:PF(SML);
			case TOK_LE:PF(LE);
			case TOK_ADD:PF(ADD);
			case TOK_SUB:PF(SUB);
			case TOK_MUL:PF(MUL);
			case TOK_DIV:PF(DIV);
			case TOK_MOD:PF(MOD);
			case TOK_LSHF:PF(LSHF);
			case TOK_RSHF:PF(RSHF);
			case TOK_LBK:{
				readtok(TOK_LBK);
				concat(s,parse_expr(0));
				readtok(TOK_RBK);
				s.push_back(GETADDR);
				break;
			}
			case TOK_DOT:curtok++;concat(s,parse_expr(prior(TOK_DOT)));break;
			case TOK_LPR:{
				uint argcnt;
				readtok(TOK_LPR);concat(s,parse_args(TOK_RPR,argcnt));readtok(TOK_RPR);
				concat(s,compile_call(argcnt));
				break;
			}
			case TOK_RPR:case TOK_RBK:return s;
			case TOK_FEN:nexttok();return s;
			default:return s;
		}
	}
	return s;
}
codeset parse_args(char end,uint &c){
	codeset s;c=0;
	while(tok.type!=end){
		concat(s,parse_expr(20)),c++;
		if(tok.type==TOK_COM)readtok(TOK_COM); 
	}
	return s; 
}
vector<int> parse_params(uint &c,codeset&arg,char ender){
	vector<int> s;c=0;
	while(tok.type!=ender){
		if(tok.type==TOK_AND)readtok(TOK_AND);
		s.push_back(getid(readtok(TOK_ID).val,1));
		if(tok.type==TOK_COL){
			nexttok();string t=tok.val;nexttok();
			if(!isalpha(t[0]))fatal("expected a type name after ':', not %s",tokenname[(uint)tok.type]);
			concat(arg,checktype(c,"'"+t+"'"));
		}
		c++;
		if(tok.type==TOK_COM)readtok(TOK_COM); 
	}
	return s;
}
codeset parse_decl(){
	codeset s,T;
	while(tok.type==TOK_ID){
		token t=readtok(TOK_ID);
		if(tok.type==TOK_ASS)readtok(TOK_ASS),concat(T,parse_expr(20));
		else T.push_back(LOADNULL);
		T.push_back(ASSIGNLOCAL);
		concat(s,compile_localvar(getid(t.val,1)));
		concat(s,T);
		if(tok.type!=TOK_COM)break;
		else readtok(TOK_COM);
	}
	return s;
}
codeset parse_obj(){
	codeset s,b1,b2;uint c=0;
	while(tok.type!=TOK_RBR){
		if(tok.type==TOK_ID||tok.type==TOK_NUM||tok.type==TOK_TRUE||tok.type==TOK_FALSE||tok.type==TOK_NULL||tok.type==TOK_UNDEFINED){
			b1=compile_str('"'+tok.val+'"');
		}
		else if(tok.type==TOK_STR)b1=compile_str(tok.val);
		else fatal("expected a property name at line %d, column %d (given: '%s')",tok.line,tok.column,tokenname[(uint)tok.type]);
		nexttok(),readtok(TOK_COL);
		b2=parse_expr(0);
		if(tok.type==TOK_COM)readtok(TOK_COM);
		c++;
		concat(s,b2),concat(s,b1);
	}
	s.push_back(LOADOBJ);
	concat(s,loadint(c));
	return s;
}
codeset compile_if();
codeset compile_while();
codeset compile_for();
codeset compile_forall();
codeset compile_func();
codeset compile_hold(uchar);
codeset compile_class();
codeset compile(){
	codeset s;
	switch(tok.type){
		case TOK_IF:readtok(TOK_IF);concat(s,compile_if());break; 
		case TOK_LBR:readtok(TOK_LBR);concat(s,compile_block());readtok(TOK_RBR);break;
		case TOK_WHILE:readtok(TOK_WHILE);concat(s,compile_while());break;
		case TOK_RET:readtok(TOK_RET);{
			if(tok.type==TOK_FEN)s.push_back(LOADNULL);
			else concat(s,parse_expr(0));
			s.push_back(RETURN);break;
		}
		case TOK_FOR:readtok(TOK_FOR);concat(s,compile_for());break;
		case TOK_FUNC:{
			if(curtok+1<toks.size()&&toks[curtok+1].type==TOK_ID){
				readtok(TOK_FUNC),concat(s,compile_func()),s.push_back(POP);
			}
			else concat(s,parse_expr(0)),s.push_back(POP);
			break;
		}
		case TOK_BREAK:readtok(TOK_BREAK);concat(s,compile_hold(BREAKHOLDER));break;
		case TOK_CTN:readtok(TOK_CTN);concat(s,compile_hold(CTNHOLDER));break;
		case TOK_VAR:readtok(TOK_VAR),concat(s,parse_decl());break;
		case TOK_CLASS:readtok(TOK_CLASS),concat(s,compile_class());break;
		default:concat(s,parse_expr(0));s.push_back(POP);break;
	}
	if(tok.type==TOK_FEN)readtok(TOK_FEN);
	return s;
}
void fillholder(codeset&s,const uint&bsize,const uint&stepsize){
	codeset b;
	for(uint i=0;i+8<s.size();i++){
		if(
			s[i]==BREAKHOLDER&&s[i+1]==BREAKHOLDER&&s[i+2]==BREAKHOLDER&&
			s[i+3]==BREAKHOLDER&&s[i+4]==BREAKHOLDER&&s[i+5]==BREAKHOLDER&&
			s[i+6]==BREAKHOLDER&&s[i+7]==BREAKHOLDER&&s[i+8]==BREAKHOLDER
		){
			uint offset=s.size()-i-4+stepsize-1;
			
			s[i]=JUMP,b=loadint(offset);
			s[i+1]=b[0],s[i+2]=b[1],s[i+3]=b[2],s[i+4]=b[3];
			s[i+5]=NOP,s[i+6]=NOP,s[i+7]=NOP,s[i+8]=NOP;
		}
		if(
			s[i]==CTNHOLDER&&s[i+1]==CTNHOLDER&&s[i+2]==CTNHOLDER&&
			s[i+3]==CTNHOLDER&&s[i+4]==CTNHOLDER&&s[i+5]==CTNHOLDER&&
			s[i+6]==CTNHOLDER&&s[i+7]==CTNHOLDER&&s[i+8]==CTNHOLDER
		){
			uint offset=s.size()-i-4-6;
			s[i]=JUMP,b=loadint(offset);
			s[i+1]=b[0],s[i+2]=b[1],s[i+3]=b[2],s[i+4]=b[3];
			s[i+5]=NOP,s[i+6]=NOP,s[i+7]=NOP,s[i+8]=NOP;
		}
	}
}
codeset compile_block(bool frame){
	codeset s;
	if(frame)s.push_back(NEWFRAME);
	new_scope();
	while(tok.type!=TOK_RBR)concat(s,compile());
	del_scope();
	if(frame)s.push_back(DELFRAME);
	return s;
}
codeset compile_if(){
	codeset s=parse_expr(0);
	codeset b1=compile();
	codeset b2=codeset();
	if(tok.type==TOK_ELSE)readtok(TOK_ELSE),b2=compile();
	concat(b1,compile_jump(b2.size()));// IMPORTNAT
	concat(s,compile_jif(b1.size()));
	concat(s,b1);
	concat(s,b2);
	return s;
}
codeset compile_while(){
	codeset s;
	s.push_back(NEWFRAME);
	concat(s,parse_expr(0));
	codeset b=compile();
	concat(b,compile_loop(b.size()+s.size()+6));//IMPORTANT
	concat(s,compile_jif(b.size()));
	concat(s,b);
	fillholder(s,b.size(),0);
	s.push_back(DELFRAME);
	return s;
}
codeset compile_for(){
	if(tok.type==TOK_ALL)return readtok(TOK_ALL),compile_forall();
	new_scope();
	readtok(TOK_LPR);
	codeset s=parse_expr(0);
	s.push_back(POP);
	codeset expr=parse_expr(0);
	codeset step=parse_expr(0);
	step.push_back(POP);
	readtok(TOK_RPR);
	codeset b=compile();
	concat(s,expr);
	uint stepsize=step.size();
	uint bsize=b.size();
	concat(b,step);
	concat(b,compile_loop(b.size()+expr.size()+6));//IMPORTANT
	fillholder(b,bsize,stepsize);
	concat(s,compile_jif(b.size()));
	concat(s,b); 
	del_scope();
	return s;
}
codeset compile_forall(){
	new_scope();
	readtok(TOK_LPR);
	string iter=tok.val;readtok(TOK_ID);
	readtok(TOK_COL);
	codeset arr=parse_expr(0);
	readtok(TOK_RPR);
	string I=iter+"$_I",L=iter+"$_L",V=iter+"$_V",K=iter+"$_K";
	
	// I=0 V=arr K=keys(V) L=len(K) 
	codeset step1;
	concat(step1,compile_var((getid(I))));
	concat(step1,compile_num(0));
	step1.push_back(ASSIGN);
	step1.push_back(POP);
	concat(step1,compile_var((getid(V))));
	concat(step1,arr);
	step1.push_back(ASSIGN);
	step1.push_back(POP);
	concat(step1,compile_var(getid(K)));
	concat(step1,compile_var(getid("keys")));
	concat(step1,compile_var(getid(V)));
	concat(step1,compile_call(1));
	step1.push_back(ASSIGN);
	step1.push_back(POP);
	concat(step1,compile_var(getid(L)));
	concat(step1,compile_var(getid("len")));
	concat(step1,compile_var(getid(K)));
	concat(step1,compile_call(1));
	step1.push_back(ASSIGN);
	step1.push_back(POP);
	
	// I<L
	codeset step2;
	concat(step2,compile_var(getid(I)));
	concat(step2,compile_var(getid(L)));
	step2.push_back(SML);
	
	// I+=1
	codeset step3;
	concat(step3,compile_var(getid(I)));
	concat(step3,compile_num(1));
	step3.push_back(ADDE);
	step3.push_back(POP);
	
	// iter=K[I]
	codeset pre;
	concat(pre,compile_var(getid(iter)));
	concat(pre,compile_var(getid(K)));
	concat(pre,compile_var(getid(I)));
	pre.push_back(GETADDR);
	pre.push_back(ASSIGN);
	pre.push_back(POP);
	
	codeset s=step1;
	codeset expr=step2;
	codeset step=step3;
	concat(pre,compile());
	codeset b=pre;
	concat(s,expr);
	uint stepsize=step.size();
	uint bsize=b.size();
	concat(b,step);
	concat(b,compile_loop(b.size()+expr.size()+6));//IMPORTANT
	fillholder(b,bsize,stepsize);
	concat(s,compile_jif(b.size()));
	concat(s,b); 
	del_scope();
	return s;
}
vector<int> get_used_upvalue(){
	vector<int> s;
	for(auto a:used_upvalues[used_upvalues.size()-1])s.push_back(a);
	return s;
}
codeset compile_upvalue(string fid){
	codeset s;
	for(auto a:used_upvalues[used_upvalues.size()-1])concat(s,loadint(a));
	return s;
}
codeset compile_func(){
	codeset s,b2,pc;
	
	string name=readtok(TOK_ID).val;
	uint tmp;
	concat(s,compile_var(getid(name)));
	new_scope();
	readtok(TOK_LPR);vector<int> b1=parse_params(tmp,pc);readtok(TOK_RPR);
	readtok(TOK_LBR);concat(b2,pc),concat(b2,compile_block(0));readtok(TOK_RBR);
	b2.push_back(LOADUNDEFINED),b2.push_back(RETURN);
	// b2 -> instr
	// used_upvalues[used_upvalues.size()-1] -> upvs
	// b1 -> pid
	uint slot_id=func_slot(b1,b2,get_used_upvalue());
	del_scope();
	concat(s,compile_loadfunc(slot_id));
	s.push_back(ASSIGN);
	return s;
}
uint used_lambdas;
codeset compile_lambda(){
	codeset s,b2,pc;
	string name="$LAMBDA_"+num2str(++used_lambdas);
	uint tmp;
	concat(s,compile_var(getid(name)));
	new_scope();
	readtok(TOK_SML);vector<int> b1=parse_params(tmp,pc,TOK_BIG);readtok(TOK_BIG);
	readtok(TOK_ARW);concat(b2,pc),concat(b2,parse_expr(0)),b2.push_back(RETURN);
	uint slot_id=func_slot(b1,b2,get_used_upvalue());
	del_scope();
	concat(s,compile_loadfunc(slot_id));
	s.push_back(ASSIGN);
	return s;
}
string getoperator(){
	switch(tok.type){
		#define checkret(c,s)\
		case TOK_##c:nexttok();return "__"#s"__";
		checkret(CHOOSE,CHOOSE);
		checkret(OR,OR);
		checkret(AND,AND);
		checkret(BITAND,BIT_AND);
		checkret(BITOR,BIT_OR);
		checkret(XOR,XOR);
		checkret(LE,SML_EQL);
		checkret(GE,BIG_EQL);
		checkret(SML,SML);
		checkret(BIG,BIG);
		checkret(HAS,HAS);
		checkret(LSHF,LSHIFT);
		checkret(RSHF,RSHIFT);
		checkret(ADD,ADD);
		checkret(SUB,SUB);
		checkret(MUL,MUL);
		checkret(DIV,DIV);
		checkret(MOD,MOD);
		checkret(NOT,NOT);
		checkret(BITNOT,BITNOT);
		default:fatal("'%s' is not a reloadable operator",tok.val.c_str());
	}
	return "";
}
codeset compile_method(string&name){
	codeset s,b2,pc;int cop=0;
	if(name=="")name=readtok(TOK_ID).val;
	else if(name=="operator")name=getoperator(),cop=1;
	else cop=2;
	uint tmp;
	new_scope();
	readtok(TOK_LPR);vector<int> b1=parse_params(tmp,pc);readtok(TOK_RPR);
	if(cop==1&&tmp==0){
		if(name=="__ADD__")name="__PST__";
		if(name=="__SUB__")name="__NGT__";
	}
	if(cop==2)name="__constructor_"+num2str(tmp)+"__";
	readtok(TOK_LBR);concat(b2,pc),concat(b2,compile_block(0));readtok(TOK_RBR);
	b2.push_back(LOADUNDEFINED),b2.push_back(RETURN);
	uint slot_id=func_slot(b1,b2,get_used_upvalue());
	concat(s,compile_loadfunc(slot_id));
	del_scope();
	return s;
}
codeset compile_hold(uchar h){
	codeset s;
	s.push_back(h),s.push_back(h),s.push_back(h),
	s.push_back(h),s.push_back(h),s.push_back(h),
	s.push_back(h),s.push_back(h),s.push_back(h);
	return s;
}
codeset compile_new(){
	readtok(TOK_NEW);
	codeset s;
	string name=readtok(TOK_ID).val;
	int tot=0;
	readtok(TOK_LPR);
	while(1){
		if(tok.type==TOK_COM)nexttok();
		else if(tok.type==TOK_RPR){nexttok();break;}
		else concat(s,parse_expr(0)),tot++;
	}
	concat(s,compile_str('"'+name+'"'));
	s.emplace_back(CONSTRUCT);
	concat(s,loadint(tot));
	return s;
}
codeset compile_class(){
	codeset s;
	string name=readtok(TOK_ID).val,superclass="object";
	if(tok.type==TOK_COL){
		readtok(TOK_COL);
		superclass=readtok(TOK_ID).val;
	}
	int tot=0;
	readtok(TOK_LBR);
	int ext=0;codeset acc;
	while(1){
		int acp=2;
		if(tok.type==TOK_PUB||tok.type==TOK_PROT||tok.type==TOK_PRIV)acp=tok.type-TOK_PUB,nexttok(),ext=1;
		if(tok.type==TOK_VAR){
			readtok(TOK_VAR);
			while(1){
				string fn=readtok(TOK_ID).val;
				tot++,concat(s,compile_str('"'+fn+'"'));
				if(tok.type==TOK_ASS){
					readtok(TOK_ASS);
					concat(s,parse_expr(0));
				}
				else s.emplace_back(LOADNULL);
				if(tok.type==TOK_COM)readtok(TOK_COM);
				else break;
			}
		}
		else if(tok.type==TOK_FUNC){
			readtok(TOK_FUNC);
			string mn="";
			codeset t=compile_method(mn);
			tot++,concat(s,compile_str('"'+mn+'"'));
			concat(s,t);
		}
		else if(tok.type==TOK_OP){
			readtok(TOK_OP);
			string mn="operator";
			codeset t=compile_method(mn);
			tot++,concat(s,compile_str('"'+mn+'"'));
			concat(s,t);
		}
		else if(tok.type==TOK_CONSTRUCTOR){
			readtok(TOK_CONSTRUCTOR);
			string mn="constructor";
			codeset t=compile_method(mn);
			tot++,concat(s,compile_str('"'+mn+name+'"'));
			concat(s,t);
		}
		else if(tok.type==TOK_FEN)readtok(TOK_FEN);
		else if(tok.type==TOK_RBR){readtok(TOK_RBR);break;}
		else fatal("unexpected '%s' in the definition of class '%s'",tokenname[(uint)tok.type],name.c_str());
		acc.push_back(acp);
	}
	concat(s,compile_str('"'+superclass+'"'));
	concat(s,compile_str('"'+name+'"'));
	s.push_back(MAKECLASS);
	concat(s,loadint(tot));
	if(ext)s.push_back(EXTENDACC),concat(s,acc);
	return s;
}
namespace vm{
const uint MAX_FILE_CNT=1024*4;
const uint RUNSTACK_SIZE=1024*1024;
typedef enum {TNUM,TSTR,TNULL,TFUNC,TREF,TTRUE,TFALSE,TUNDEF} valtype;
const char* valtypename[]={"number","string","null","function","reference","true","false","undefined"};
inline string ref2string(ull,int a=0);
inline string reftype(ull);
inline int hasfield(const ull&,const string&);
inline string strictstr(const string&);
struct val;
inline val call_op_func(const val&ref,const string&key,const val&arg);
struct val{
	double num,owner;
	uint permission,class_type;
	string str;
	uchar type;
	val(){type=TUNDEF,permission=1,class_type=0;}
	val(const double &x){type=TNUM,num=x,permission=1,class_type=0;}
	val(const string &s){type=TSTR,str=s,permission=1,class_type=0;}
	static val maketrue(){val v;v.type=TTRUE,v.permission=1,v.class_type=0;return v;}
	static val makefalse(){val v;v.type=TFALSE,v.permission=1,v.class_type=0;return v;}
	val(valtype t){type=t,permission=1,class_type=0;}
	val(int64_t ref,valtype t){type=t,num=ref,permission=1,class_type=0;}
	bool is_true()const{return !(type==TFALSE||type==TNULL||(type==TNUM&&num==0));}
	string tostr(int strict=0,int call=1)const{
		switch(type){
			case TNUM:return num2str(num);
			case TSTR:return strict?strictstr(str):str;
			case TTRUE:case TFALSE:return type==TTRUE?"true":"false";
			case TREF:return ref2string((ull)num,call);
			case TFUNC:return "<function "+num2str(num)+">";
			case TNULL:return "null";
			case TUNDEF:return "undefined";
		}
		return "?";
	}
	string gettype()const{
		switch(type){
			case TNUM:return "number";
			case TSTR:return "string";
			case TTRUE:case TFALSE:return type==TTRUE?"true":"false";
			case TREF:return reftype((ull)num);
			case TFUNC:return "function";
			case TNULL:return "null";
			case TUNDEF:return "undefined";
		}
		return "?";
	}
	#define checkop(code)\
		if(type==TREF)if(hasfield(num,(string)"__"#code"__"))return call_op_func(*this,(string)"__"#code"__",b);
	#define checkunaryop(code)\
		if(type==TREF)if(hasfield(num,(string)"__"#code"__"))return call_op_func(*this,(string)"__"#code"__",val());
	val operator+(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return num+b.num;
		if(type==TSTR&&b.type==TSTR)return str+b.str;
		if(type==TSTR||b.type==TSTR)return tostr()+b.tostr();
		checkop(ADD);
		fatal("operation '+' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#define math_method(v,code)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num;\
		checkop(code);\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	math_method(-,SUB)
	math_method(*,MUL)
	math_method(/,DIV)
	val operator%(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return fmod(num,b.num);
		checkop(MOD);
		fatal("operation '%%' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#undef math_method
	#define int_method(v,code)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return (ull)num v (ull)b.num;\
		checkop(add);\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	int_method(|,BIT_OR)
	int_method(&,BIT_AND)
	int_method(^,XOR)
	int_method(<<,LSHIFT)
	int_method(>>,RSHIFT)
	#undef int_method
	val operator<(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return (ull)num<(ull)b.num?maketrue():makefalse();
		if(type==TSTR&&b.type==TSTR)return str<b.str?maketrue():makefalse();
		checkop(SML);
		fatal("operation '<' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#define bool_method(v,code)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num?maketrue():makefalse();\
		checkop(code);\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	bool_method(<=,SML_EQL)
	bool_method(>,BIG)
	bool_method(>=,BIG_EQL)
	val operator==(const val&b)const{
		if(type!=b.type)return val(TFALSE);
		if(type==TSTR)return str==b.str?maketrue():makefalse();
		checkop(EQL);
		return num==b.num?maketrue():makefalse();
	}
	val operator!=(const val&b)const{
		checkop(NEQ);
		return ((*this)==b).is_true()?makefalse():maketrue();
	}
	#undef bool_method
	val operator+()const{
		if(type==TNUM)return +num;
		checkunaryop(PST);
		fatal("unary operation '+' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	val operator-()const{
		if(type==TNUM)return -num;
		checkunaryop(NGT);
		fatal("unary operation '-' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	val operator~()const{
		if(type==TNUM)return ~(ull)num;
		checkunaryop(BIT_NOT);
		fatal("unary operation '~' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	#define logic_method(v,code)\
	val operator v (const val&b)const{\
		checkunaryop(code);\
		return is_true() v b.is_true()?maketrue():makefalse();\
	}
	logic_method(&&,AND)
	logic_method(||,OR)
	val operator!()const{checkunaryop(NOT);return !is_true()?maketrue():makefalse();}
	#undef logic_method
	val smller(const val&v)const{
		if(v.type!=type)return false;
		switch(type){
			case TNUM:return num<v.num?maketrue():makefalse();
			case TSTR:return str>v.str?maketrue():makefalse();
			default:return type<v.type?maketrue():makefalse();
		}
		return makefalse();
	}
	val choose(const val&b)const{checkop(CHOOSE);return type==TUNDEF||type==TNULL?b:(*this);}
};
inline val initarr(const vector<val>&v,const vector<val>&id);
enum{SYSTEM_PERMISSION,GUEST_PERMISSION,THIS_PERMISSION,SUPER_PERMISSION};
const string permission_name[4]={(string)"system",(string)"guest",(string)"this",(string)"super"};
const string access_name[3]={(string)"public",(string)"protected",(string)"private"};
enum{PUBLIC,PROTECTED,PRIVATE};
namespace object_manager{
	struct class_info{
		umap<string,val>field;
		umap<string,char>access;
		umap<string,string>owner;
		string class_name,super_class;
		uint id;
	};
	uint used_cls_id;
	vector<string>used_cls;
	umap<string,class_info>classes;
	inline string get_super_class(const string&c){return classes[c].super_class;}
	inline uint get_class_id(const string&c){return classes[c].id;}
	inline uint get_super_class(uint id){return get_class_id(get_super_class(used_cls[id]));}
	void make_class(const string&class_name,const string&super_class,const umap<string,val>&field,const umap<string,int>&access,int chk=1){
		if(chk&&class_name=="object")fatal("attempting to make class named 'object'%c",' ');
		if(chk&&classes.find(super_class)==classes.end())fatal("cannot find class '%s'",super_class.c_str());
		if(chk&&class_name==super_class)fatal("attempting to make class '%s' based on itself",class_name.c_str());
		const auto&super=classes[super_class];
		auto&curcl=classes[class_name];
		curcl.field=super.field;
		curcl.access=super.access;
		curcl.owner=super.owner;
		curcl.id=used_cls_id++,used_cls.push_back(class_name);
		for(const auto&a:field)curcl.field[a.first]=a.second,curcl.owner[a.first]=class_name;
		for(const auto&a:access)curcl.access[a.first]=a.second;
		curcl.super_class=super_class;
		curcl.class_name=class_name;
	}
	val construct(const string&class_name){
		if(classes.find(class_name)==classes.end())fatal("cannot find class '%s'",class_name.c_str());
		const auto&curcl=classes[class_name];
		vector<val> vid,f; 
		vid.emplace_back("__class__"),f.emplace_back(class_name);
		vid.emplace_back("__super_class__"),f.emplace_back(curcl.super_class);
		for(auto a:curcl.field){
			string fn=a.first;
			val v=a.second;
			vid.emplace_back(fn);
			f.emplace_back(v);
		}
		return initarr(f,vid);
	}
	int is_subclass_of(string sub,const string&fa){
		if(fa=="object")return 1;
		do{
			if(sub==fa)return 1;
			if(classes.find(sub)==classes.end())fatal("cannot find class '%s'",sub.c_str());
			sub=classes[sub].super_class;
		}while(sub!="object");
		return 0;
	}
	bool check_access(string class_name,const string&field,char permission,uint class_type,string&owner){
		if(classes.find(class_name)==classes.end())fatal("cannot find class '%s'",class_name.c_str());
//		cout<<"Access: "<<field<<endl;
//		cout<<"\tpermission: "<<permission_name[uint(permission)]<<endl;
//		cout<<"\tclass_type: "<<class_type<<" or also "<<used_cls[class_type]<<endl;
//		cout<<"\tprototype: "<<class_name<<endl;
		auto&fields=classes[class_name].field;
		if(fields.find(field)==fields.end())return true;
		auto&access=classes[class_name].access[field];
		owner=classes[class_name].owner[field];
		if(class_type==0)class_type=get_class_id(class_name);
		class_name=used_cls[class_type];
		switch(permission){
			case SYSTEM_PERMISSION:return true;
			case GUEST_PERMISSION:if(access!=PUBLIC)fatal("field '%s' of class '%s' is %s",field.c_str(),class_name.c_str(),access_name[(uint)access].c_str());break;
			case THIS_PERMISSION:{
				if(owner!=class_name&&(access==PRIVATE))fatal("field '%s' of class '%s' is from class '%s', did you mean 'super'?",field.c_str(),class_name.c_str(),owner.c_str());
				break;
			}
			case SUPER_PERMISSION:{
				if(owner==class_name)fatal("field '%s' of class '%s' belongs to itself, did you mean 'this'?",field.c_str(),class_name.c_str());
				if(access==PRIVATE)fatal("field '%s' of class '%s' is from class '%s', which is private",field.c_str(),class_name.c_str(),owner.c_str());
				break;
			}
			default:fatal("unknown permission given (level: %d)",(int)permission);
		}
		
		return true;
	}
}
template <typename T>
struct pool{
	vector<T> ctt;
	uint size(){return ctt.size();};
	void resize(uint v){ctt.resize(v);};
	void push_back(const T&t){ctt.push_back(t);};
	T& operator[](const uint&loc){if(loc>ctt.size())ctt.resize(loc);return ctt[loc];}
};
template <typename T,typename R,typename cmp>
struct hashtable{
	umap<T,R,cmp> ctt;
	uint size(){return ctt.size();};
	bool has(const T&key){return ctt.find(key)!=ctt.end();}
	R& operator[](const T&loc){return ctt[loc];}
};
struct func{
	vector<int> pid,upvs;
	codeset instr;
};
const uint regoffset=2048;
const uint arrlength=1024*1024*1024;
const uint objresv=arrlength/2;
vector<hashtable<ull,val,hasher>>frames;
umap<string,ull>keyhash;
umap<ull,string>revkeyhash;
ull usedhashslot;
ull getkeyhash(const string&s){
	if(keyhash.find(s)==keyhash.end()){
		keyhash[s]=(++usedhashslot)+objresv;
		revkeyhash[keyhash[s]-objresv]=s;
		return keyhash[s];
	}
	return keyhash[s];
}
val indexval(ull x){return x>objresv?revkeyhash[x%objresv]:val(x,TNUM);}
umap<ull,umap<ull,val,hasher>,hasher>upvalueframe;
umap<ull,func,hasher>functable;
umap<ull,val,hasher>heap;
umap<ull,ull,hasher>arrlens;
umap<ull,set<ull>>indices;
umap<ull,int>is_obj;
vector<uint>regs;
vector<uint>funcstack; 
ull usedarrs;
ull usedfuncs;
ull vmstack[RUNSTACK_SIZE];
typedef ull* runstack;
inline void newframe(){frames.push_back(hashtable<ull,val,hasher>()),regs.push_back(0);}
inline void delframe(){frames.pop_back(),regs.pop_back();}
inline val& generef(const ull&addr,bool lcl=0){
	if(addr<0)return heap[addr];
	if(addr>=0&&!lcl){
		for(uint i=frames.size()-1;~i;i--)if(frames[i].has(addr))return frames[i][addr];
		if(upvalueframe[funcstack[funcstack.size()-1]].find(addr)!=upvalueframe[funcstack[funcstack.size()-1]].end())return upvalueframe[funcstack[funcstack.size()-1]][addr];
	}
	return frames[frames.size()-1][addr];
}
inline val& localref(ull addr){return frames[frames.size()-1][addr]=val(TNULL),frames[frames.size()-1][addr];}
inline ull newreg(){return regs.size()*regoffset+(++regs[regs.size()-1]);}
inline void delreg(){regs[regs.size()-1]--;}
inline void freereg(const uint&addr){for(ull i=frames.size()-1;~i;i--)if(frames[i].has(addr))frames[i].ctt.erase(addr);}
inline ull allocarr(){return arrlens[++usedarrs]=-1,arrlength*(usedarrs);}
inline ull getarrid(ull x){return x/arrlength;}
inline ull getlen(val v){
	ull addr;
	if(v.type==TSTR)return v.str.length();
	if(v.type==TREF){
		if(is_obj[getarrid(v.num)])fatal("trying getting length of reference of an object%c",' ');
		return addr=v.num,arrlens[(addr)/arrlength]+1;
	}
	fatal("type '%s' has no length property",valtypename[uint(v.type)]);
	return 0;
}
inline void mdfaddr(ull addr,int del=0){
	if(addr>=0)return;
	addr=-addr;
	ull id=getarrid(addr);
	if(addr%arrlength>objresv)is_obj[id]=1;
	if(!del){
		indices[id].insert(addr);
		if(!is_obj[id])arrlens[id]=max(arrlens[id],addr%arrlength);
	}
	else{
		indices[id].erase(addr); 
		if(!is_obj[id])arrlens[id]=arrlens[id]-1;
	}
}
inline int hasfield(const ull&ref,const string&key){
	ull addr=ref+getkeyhash(key),id=getarrid(addr);
	return indices[id].find(addr)!=indices[id].end();
}
inline val hasfield(const val&obj,const val&key){
	if(obj.type!=TREF)return val(0,TTRUE);
	ull addr;
	if(key.type==TNUM)addr=obj.num+key.num;
	else if(key.type==TSTR)addr=obj.num+getkeyhash(key.str);
	else return val(0,TFALSE);
	ull id=getarrid(addr);
	return val(0,indices[id].find(addr)!=indices[id].end()?TTRUE:TFALSE);
}
inline int isa(const val&sub,const val&fa){
	if(fa.type!=TSTR)fatal("'is' operator requires type 'string' for right operands, not '%s'",valtypename[fa.type]);
	string f=fa.str;
	switch(sub.type){
		case TNUM:return f=="number";
		case TSTR:return f=="string";
		case TTRUE:return f=="true";
		case TFALSE:return f=="false";
		case TNULL:return f=="null";
		case TUNDEF:return f=="undefined";
		case TFUNC:return f=="function";
		case TREF:return vm::object_manager::is_subclass_of(sub.gettype(),f);
	}
	return 0;
}
umap<char,umap<string,ull>> builtinmethod;
inline int builtin_method(char type,const string&s,ull&r){
	if(builtinmethod[type].find(s)!=builtinmethod[type].end())return r=builtinmethod[type][s],1;
	return 0;
}
inline int access_level(const string&t,const string&f){
	if(vm::object_manager::classes.find(t)==vm::object_manager::classes.end())return 0;
	return vm::object_manager::classes[t].access[f];
}
string getaddr_returnval;
inline ull getaddr(const val&addr,const val&offset,char permission=SYSTEM_PERMISSION,int class_type=0){
	ull r=0;
	if(addr.type==TSTR&&offset.type==TNUM){generef(r=newreg())=val((addr.str.size()>offset.num?((string)"")+addr.str[int(offset.num)]:""));return r;}
	else if(addr.type==TREF&&offset.type==TNUM)return(-(addr.num+offset.num));
	else if(addr.type==TREF&&offset.type==TSTR){
		if(builtin_method(addr.type,offset.str,r))return r;
		if(permission!=SYSTEM_PERMISSION&&!object_manager::check_access(addr.gettype(),offset.str,permission,class_type,getaddr_returnval))fatal("Access denied: attempt to access private field '%s' from type '%s'",offset.str.c_str(),addr.gettype().c_str());
		return (-(addr.num+getkeyhash(offset.str)));
	}
	else if(offset.type==TSTR){if(builtin_method(addr.type,offset.str,r))return r;}
	else fatal("operation '[]' can't be applied between '%s' and '%s'",valtypename[addr.type],valtypename[offset.type]);
	return r;
}
inline ull newfunc(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	usedfuncs++,functable[usedfuncs].pid=pid,functable[usedfuncs].instr=instr,functable[usedfuncs].upvs=upvs;
	for(auto a:upvs)upvalueframe[usedfuncs][a]=generef(a);
	return usedfuncs;
}
ull call_func(const int&fid,const vector<ull>&args,runstack stk_start,ull this_obj=0,uint this_type=0);
int runbytes(const codeset&s,const vector<val>&args,const int &fid,runstack stk_start,ull this_obj=0,uint this_type=0){
	uint ip=0,len=s.size();
	runstack curstk=stk_start;
	#define BACK\
	ip++;\
	goto DECODE
	while(ip<len){
		DECODE:
		if(ip>=len)break;
//		printf("ip=%d, code=%X\n",ip,s[ip]);
//		for(runstack i=stk_start;i<curstk;i++)cout<<"\t"<<generef(*i).tostr(0,0)<<" ["<<permission_name[generef(*i).permission]<<"]"<<" <class "<<object_manager::used_cls[generef(*i).class_type]<<">"<<endl;
//		cout<<endl;
		switch(s[ip]){
			default:{
				fatal("unknown bytecode %02X at position %d",s[ip],ip);
				BACK;
			}
			#define loader(x)\
			case LOAD##x:{\
				ull nr=newreg();generef(nr)=val(x,TNUM),*curstk=nr,curstk++;\
				break;\
			}
			loader(0) loader(1) loader(2) loader(3) 
			loader(4) loader(5) loader(6) loader(7) 
			loader(8) loader(9) loader(10) loader(11) 
			loader(12) loader(13) loader(14) loader(15)
			case LOAD1BIT:case LOAD2BIT:case LOAD3BIT:case LOAD4BIT:{
				uint v=s[ip]-0x20,t=0,z=0;
				while(t<v)z=z*256+s[++ip],t++;
				ull nr=newreg();generef(nr)=val(z,TNUM),*curstk=nr,curstk++;
				break;
			}
			#undef loader
			case LOADSTR:{
				string str="";
				ip++;
				uint id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				uchar v=0;
				while(id--)v=s[ip+1]*0xfu+s[ip+2],ip+=2,str.push_back(v);
				*curstk=newreg();
				generef(*curstk)=val(str),curstk++;
				BACK;
			}
			case STRSLOT:case STRSLOT1B:case STRSLOT2B:case STRSLOT3B:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case STRSLOT1B:id=s[ip];break;
					case STRSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case STRSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case STRSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				*curstk=newreg();
				generef(*curstk)=val(str_pool[id]),curstk++;
				break;
			}
			case NUMSLOT:case NUMSLOT1B:case NUMSLOT2B:case NUMSLOT3B:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case NUMSLOT1B:id=s[ip];break;
					case NUMSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case NUMSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case NUMSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				*curstk=newreg();
				generef(*curstk)=val(num_pool[id]),curstk++;
				break;
			}
			case LOADTRUE:{
				ull nr=newreg();generef(nr)=val(0,TTRUE),*curstk=nr,curstk++;
				BACK;
			}
			case LOADFALSE:{
				ull nr=newreg();generef(nr)=val(0,TFALSE),*curstk=nr,curstk++;
				BACK;
			}
			case LOADNULL:{
				ull nr=newreg();generef(nr)=val(0,TNULL),*curstk=nr,curstk++;
				BACK;
			}
			case LOADUNDEFINED:{
				ull nr=newreg();generef(nr)=val(0,TUNDEF),*curstk=nr,curstk++;
				BACK;
			}
			case LOADVAR:case LOADVARLOCAL:case LOCALVAR1B:case LOCALVAR2B:case LOCALVAR3B:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case LOCALVAR1B:id=s[ip];break;
					case LOCALVAR2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case LOCALVAR3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case LOADVAR:case LOADVARLOCAL:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				*curstk=id,curstk++;
				generef(id).permission=GUEST_PERMISSION;
				BACK;
			}
			case ASSIGN:case ASSIGNLOCAL:{
				generef(*(curstk-2),s[ip]==ASSIGNLOCAL)=generef(*(curstk-1)),mdfaddr(*(curstk-2));
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
				BACK;
			}
			#define assigner(tokname,op)\
			case tokname:{\
				generef(*(curstk-2),0)=generef(*(curstk-2),0) op generef(*(curstk-1)),mdfaddr(*(curstk-2));\
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));\
				curstk--;\
				BACK;\
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
				*curstk=newreg();
				generef(*curstk)=val(bpser8.x),curstk++;
				BACK;
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
				*curstk=newreg();
				generef(*curstk)=val(bpser.x),curstk++;
				BACK;
			}
			case POP:{
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;BACK;
			}
			#define MATH(v,sym)\
			case v:{\
				uint nr=newreg();\
				generef(nr)=generef(*(curstk-2)) sym generef(*(curstk-1));\
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));\
				curstk--,*(curstk-1)=nr;\
				BACK;\
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
			case HAS:{
				uint nr=newreg();
				generef(nr)=hasfield(generef(*(curstk-2)),generef(*(curstk-1)));
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
				BACK;
			}
			case CHOOSE:{
				uint nr=newreg();
				generef(nr)=generef(*(curstk-2)).choose(generef(*(curstk-1)));
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
				BACK;
			}
			case ISA:{
				uint nr=newreg();
				generef(nr)=isa(generef(*(curstk-2)),generef(*(curstk-1)))?val(1,TTRUE):val(0,TFALSE);
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
				BACK;
			}
			MATH(BITAND,&);
			MATH(BITOR,|);
			MATH(LSHF,<<);
			MATH(RSHF,>>);
			MATH(XOR,^);
			case AND:case AND1B:case AND2B:case AND3B:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case AND1B:id=s[ip];break;
					case AND2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case AND3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case AND:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				bool cond=generef(*(curstk-1)).is_true();
				if(!cond)ip+=id;
				else{
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				BACK;
			}
			case OR:case OR1B:case OR2B:case OR3B:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case OR1B:id=s[ip];break;
					case OR2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case OR3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case OR:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				bool cond=generef(*(curstk-1)).is_true();
				if(cond)ip+=id;
				else{
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				BACK;
			}
			#undef MATH
			#define UNARY(v,sym)\
			case v:{\
				uint nr=newreg();\
				generef(nr)=sym generef(*(curstk-1));\
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));\
				*(curstk-1)=nr;\
				BACK;\
			}
			UNARY(NOT,!);
			UNARY(BITNOT,~);
			UNARY(POSITIVE,+);
			UNARY(NEGATIVE,-);
			case TYPEOF:{
				uint nr=newreg();
				generef(nr)=generef(*(curstk-1)).gettype();
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				*(curstk-1)=nr;
				BACK;
			}
			#undef UNARY
			case LOADARR:{
				ip++;
				int len=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				ull loc=allocarr(),nr=newreg();
				while(len--){
					generef(-(loc+len))=generef(*(curstk-1)),mdfaddr(-(loc+len));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				generef(nr)=val(loc,TREF),*curstk=nr,curstk++;
				BACK;
			}
			case LOADOBJ:{
				ip++;
				ull len=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				ull loc=allocarr(),nr=newreg();
				is_obj[getarrid(loc)]=1;
				val r=val(loc,TREF),key; 
				while(len--){
					key=generef(*(curstk-1));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
					generef(getaddr(r,key))=generef(*(curstk-1)),mdfaddr(getaddr(r,key));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				generef(nr)=r,*curstk=nr,curstk++;
				BACK;
			}
			case GETADDR:{
				ull nr=getaddr(generef(*(curstk-2)),generef(*(curstk-1)),generef(*(curstk-2)).permission,generef(*(curstk-2)).class_type);
				generef(nr).owner=*(curstk-2),generef(nr).permission=GUEST_PERMISSION,generef(nr).class_type=object_manager::get_class_id(getaddr_returnval);
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
				BACK;
			}
			case FUNCSLOT1B:case FUNCSLOT2B:case FUNCSLOT3B:case FUNCSLOT:{
				uchar a=s[ip++];
				uint id;
				switch(a){
					case FUNCSLOT1B:id=s[ip];break;
					case FUNCSLOT2B:id=s[ip]*0xff+s[ip+1],ip+=1;break;
					case FUNCSLOT3B:id=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case FUNCSLOT:id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				ull nr=newreg();
				ull fid=newfunc(func_pool[id].pid,func_pool[id].instr,func_pool[id].upvs);
				generef(nr)=val(fid,TFUNC);
				*curstk=nr,curstk++;
				BACK;
			}
			case LOADFUNC:{
				ip++;
				uint pcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				uint size=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				uint upvcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=4;
				ull nr=newreg();
				vector<int> pid,upvs;codeset instr;
				while(pcnt--)pid.push_back(s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(upvcnt--)upvs.push_back(s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(size--)instr.push_back(s[ip]),ip++;
				ip--;
				ull fid=newfunc(pid,instr,upvs);
				generef(nr)=val(fid,TFUNC);
				*curstk=nr,curstk++;
				BACK;
			}
			case CALL:case CALL1B:case CALL2B:case CALL3B:{
				uchar a=s[ip++];
				uint argscnt;
				switch(a){
					case CALL1B:argscnt=s[ip];break;
					case CALL2B:argscnt=s[ip]*0xff+s[ip+1],ip+=1;break;
					case CALL3B:argscnt=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case CALL:argscnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				uint argscnt_=argscnt;
				vector<ull> args,freelist;
				while(argscnt--){
					args.push_back(*(curstk-1));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
					curstk--;
				}
				ull fid,_this,_type;
				uint permission=generef(*(curstk-1)).permission,class_type=generef(*(curstk-1)).class_type;
				switch(permission){
					case THIS_PERMISSION:case SUPER_PERMISSION:{
						string clsname=generef(*(curstk-1)).gettype();
						if(permission==SUPER_PERMISSION)clsname=object_manager::get_super_class(clsname);
						ull nr=newreg();
						string constructor_name="__constructor_"+num2str(argscnt_)+"__"+clsname;
						if(!hasfield(generef(*(curstk-1)),constructor_name).is_true()){
							if(argscnt)fatal("class '%s' has no constructor receiving %d argument%c",clsname.c_str(),argscnt_,argscnt==1?' ':'s');
							else break;
						}
						if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
						_this=nr,fid=generef(getaddr(generef(*(curstk-1)),constructor_name)).num;
						nr=call_func(fid,args,curstk,*(curstk-1),object_manager::get_class_id(clsname));curstk--;*curstk=nr,curstk++;
						break;
					}
					default:{
						if(generef(*(curstk-1)).type!=TFUNC)fatal("can't call a non-function type '%s'(%s)",valtypename[generef(*(curstk-1)).type],generef(*(curstk-1)).tostr().c_str());
						fid=generef(*(curstk-1)).num,_this=generef(*(curstk-1)).owner,_type=generef(*(curstk-1)).class_type;
						if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
						curstk--;ull nr=call_func(fid,args,curstk,_this,_type);*curstk=nr,curstk++;
						break;
					}
				}	
				for(auto a:freelist)freereg(a);
				BACK;
			}
			case RETURN:{
				ull nr=newreg();
				generef(nr)=generef(*(curstk-1));
				return nr;
			}
			case JUMP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3+offset;
				BACK;
			}
			case JUMP_IF_FALSE:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				bool cond=generef(*(curstk-1)).is_true();
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
				if(!cond)ip+=offset;
				BACK;
			}
			case LOOP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip-=1+offset;
				BACK;
			}
			case LOADTHIS:{
				if(this_obj==0)fatal("'this' should not appear in non-objective-functions%c",' ');
				*curstk=this_obj,generef(*curstk).permission=THIS_PERMISSION,generef(*curstk).class_type=this_type,curstk++;
				BACK;
			}
			case LOADSUPER:{
				if(this_obj==0)fatal("'super' should not appear in non-objective-functions%c",' ');
				*curstk=this_obj,generef(*curstk).permission=SUPER_PERMISSION,generef(*curstk).class_type=this_type,curstk++;
				BACK;
			}
			case MAKECLASS:{
				ip++;
				uint fieldcnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				string clsname=generef(*(curstk-1)).str;
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));curstk--;
				string supname=generef(*(curstk-1)).str;
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));curstk--;
				umap<string,val>raw;umap<string,int>access;vector<string>fields;
				while(fieldcnt--){
					val v=generef(*(curstk-1));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
					string key=(generef(*(curstk-1)).str);
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
					fields.push_back(key),raw[key]=v,access[key]=0;
				}
				reverse(fields.begin(),fields.end());
				if(s[ip+1]==EXTENDACC){
					ip++;
					for(auto a:fields)access[a]=s[++ip];
				}
				object_manager::make_class(clsname,supname,raw,access);
				break;
			}
			case CONSTRUCT:case CONSTRUCT1B:case CONSTRUCT2B:case CONSTRUCT3B:{
				uchar a=s[ip++];
				uint argscnt;
				switch(a){
					case CONSTRUCT1B:argscnt=s[ip];break;
					case CONSTRUCT2B:argscnt=s[ip]*0xff+s[ip+1],ip+=1;break;
					case CONSTRUCT3B:argscnt=s[ip]*0xffff+s[ip+1]*0xff+s[ip+2],ip+=2;break;
					case CONSTRUCT:argscnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3],ip+=3;break;
				}
				uint argscnt_=argscnt;
				vector<ull> args,freelist;
				string clsname=generef(*(curstk-1)).str;
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
				curstk--;
				while(argscnt--){
					args.push_back(*(curstk-1));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
					curstk--;
				}
				ull newobj=newreg();
				generef(newobj)=object_manager::construct(clsname);
				*curstk=newobj,curstk++;
				string constructor_name="__constructor_"+num2str(argscnt_)+"__"+clsname;
				if(!hasfield(generef(newobj),constructor_name).is_true()){
					if(argscnt_)fatal("class '%s' has no constructor receiving %d argument%c",generef(newobj).gettype().c_str(),argscnt_,argscnt==1?' ':'s');
					else break;
				}
				ull fid=generef(getaddr(generef(newobj),constructor_name)).num,_this=newobj;
				call_func(fid,args,curstk,_this,object_manager::get_class_id(clsname));
				generef(newobj).permission=GUEST_PERMISSION,generef(newobj).class_type=object_manager::get_class_id(clsname);
				break;
			}
			case CHECKTYPE:{
				ip++;
				uint argnum=s[ip]*0xff+s[ip+1];
				ip++;
				string tname=generef(*(curstk-1)).str;
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));curstk--;
				if(!isa((args[argnum]),tname))fatal("<function %d> requires type '%s' as argument %d, received type '%s'",fid,tname.c_str(),argnum,(args[argnum]).gettype().c_str());
				break;
			}
			case NEWFRAME:newframe();BACK;
			case DELFRAME:delframe();BACK;
		}
		ip++;
	}
	#undef BACK
	return 0;
}
set<ull> builtin;
namespace file_manager{
	char fbuffer[2048];
	FILE *file_ptrs[MAX_FILE_CNT];
	int size;
	inline int file_open(string file,string mode="r") {
		bool write=false;
		if(strchr(mode.c_str(),'w')!=NULL)write=true;
		FILE *ptr=fopen(file.c_str(),mode.c_str());
		if(ptr==NULL){
			if(write){ofstream fcout(file.c_str());fcout.close();}
			else exit(puts(("file doesn't exist: "+file).c_str())&&0);
		}
		file_ptrs[size++]=ptr;
		return size-1;
	}
	inline void check_handle(int handle){if(handle<0||handle>=size)exit(puts(("invalid handle: "+num2str(handle)).c_str())&&0);}
	inline bool file_close(int handle){check_handle(handle);return fclose(file_ptrs[handle]);}
	inline bool file_eof(int handle){check_handle(handle);return feof(file_ptrs[handle]);}
	inline string fread_string(int handle){check_handle(handle);fscanf(file_ptrs[handle],"%s",fbuffer);return fbuffer;}
	inline string fread_line(int handle){
		check_handle(handle);string result="";
		char c=fgetc(file_ptrs[handle]);
		while(c!='\n'&&!feof(file_ptrs[handle]))result+=c,c=fgetc(file_ptrs[handle]);
		return result;
	}
	void fwrite_string(int handle,string text){check_handle(handle);fprintf(file_ptrs[handle],"%s",text.c_str());fflush(file_ptrs[handle]);}
	inline double fread_number(int handle){check_handle(handle);return atof(fread_string(handle).c_str());}
	inline void fwrite_number(int handle,double x){check_handle(handle);fprintf(file_ptrs[handle],"%.14Lg",x);fflush(file_ptrs[handle]);}
	inline double read_number(){double d;cin>>d;return d;}
	inline string read_string(){string s;cin>>s;return s;}
	inline string read_line(){string s;getline(cin,s);return s;}
	inline string read_getchar(){char c=getchar();return (string)""+c;}
	inline bool read_eof(){return cin.eof();}
};
namespace utils{
	inline string substring(const string&s,const val&from,const val&to){
		if(from.type==TUNDEF&&to.type==TUNDEF)return s;
		if(from.type!=TNUM)fatal("should not use '%s'(%s) as substring indice",from.tostr().c_str(),valtypename[from.type]);
		int a=from.num,b;
		if(to.type==TUNDEF)b=s.size()-1;
		else if(to.type==TNUM)b=to.num;
		else fatal("should not use '%s'(%s) as substring indice",to.tostr().c_str(),valtypename[to.type]);
		a=a<0?0:a,b=b<0?0:b,b=(unsigned int64_t)b>=s.size()?s.size()-1:b;
		string r="";
		for(int i=a;i<=b;i++)r+=s[i];
		return r;
	}
	inline string substr(const string&s,int from,int len){
		from=from<0?0:from,from=(unsigned int64_t)from>=s.size()?s.size()-1:from;
		len=len<0?0:len,len=(unsigned int64_t)len>(s.size()-from)?(s.size()-from):len;
		return s.substr(from,len);
	}
	inline string changecase(const string&s,int lower=0){
		string r="";
		for(auto a:s)r+=char(lower?tolower(a):toupper(a));
		return r;
	}
	inline int startswith(const string&s,const string&pre){
		if(pre.size()>s.size())return 0;
		else return s.substr(0,pre.size())==pre;
	}
	inline int endswith(const string&s,const string&suf){
		if(suf.size()>s.size())return 0;
		else return s.substr(s.size()-suf.size(),suf.size())==suf;
	}
	inline string trim(const string&s){
		int x=0,y=s.size()-1;
		while(isspace(s[x])&&x<=y)x++;
		while(isspace(s[y])&&x<=y)y--;
		return s.substr(x,y-x+1);
	}
	inline string fmtprint(const string&f,const vector<val>&v){
		uint len=f.size();
		string r="";
		for(uint i=0;i<len;i++){
			if(f[i]=='{'){
				uint idx=0,ok=0;i++;
				while(i<len&&f[i]!='}'){
					if(!isdigit(f[i]))fatal("invalid format string '%s': invalid index character '%c'",f.c_str(),f[i]);
					idx=(idx<<3)+(idx<<1)+(f[i]&15),i++,ok=1;
				}
				if(f[i]!='}')fatal("invalid format string '%s': unterminated '{'",f.c_str());
				if(!ok)fatal("invalid format string '%s': expected an index at position %d",f.c_str(),i);
				if(idx>=v.size())fatal("invalid format string '%s': unprovided value index %d",f.c_str(),idx);
				r+=v[idx].tostr();
			}
			else if(f[i]=='}')fatal("invalid format string '%s': unmatched '}'",f.c_str());
			else r+=f[i];
		}
		return r;
	}
	inline string repeatstr(const string&_,int times){
		string f=_,ans="";
		for(;times;times>>=1,f=f+f)if(times&1)ans=ans+f;
		return ans;
	}
	// Its not a good idea to use KMP so I dont
	inline string replacestr(const string&_,const string&rpl,const string&use){
		string f=_;
		uint x=f.find(rpl);
		if(x==string::npos)return f;
		return f.replace(x,rpl.size(),use);
	}
	inline val splitstr(const string&_,const string&rpl){
		size_t x=_.find(rpl),lst=0;
		vector<string> ret;
		while(x!=string::npos){
			if(x>lst)ret.push_back(_.substr(lst,x-lst));
			lst=x+1,x=_.find(rpl,lst); 
		}
		if(lst!=_.size())ret.push_back(_.substr(lst));
		ull loc=allocarr();
		for(uint i=0;i<ret.size();i++)generef(-(loc+i))=val(ret[i]),mdfaddr(-(loc+i));
		return val(loc,TREF);
	}
	inline int indexof(const string&_,const string&rpl,const val&from){
		int start=0;
		if(from.type==TUNDEF)start=0;
		else if(from.type==TNUM)start=from.num;
		else fatal("should not use '%s'(%s) as indexing indice",from.tostr().c_str(),valtypename[from.type]);
		start=start<0?0:start,start=(unsigned int64_t)start>=_.size()?_.size()-1:start; 
		uint x=_.find(rpl,start);
		if(x==string::npos)return -1;
		return x;
	}
	inline val arrindices(ull ref){
		ull id=getarrid(ref);
		ull loc=allocarr();
		vector<val>ret;
		for(auto a:indices[id])ret.push_back(indexval(a%arrlength));
		for(uint i=0;i<ret.size();i++)generef(-(loc+i))=ret[i],mdfaddr(-(loc+i));
		return val(loc,TREF);
	}
	inline val arrsort(ull ref){
		ull id=getarrid(ref);
		if(is_obj[id])fatal("object is not sortable%c",' ');
		ull loc=allocarr();
		vector<val>ret;
		for(auto a:indices[id])ret.push_back(generef(-a));
		sort(ret.begin(),ret.end(),[](const val&a,const val&b){return (a.smller(b)).is_true();});
		for(uint i=0;i<ret.size();i++)generef(-(loc+i))=ret[i],mdfaddr(-(loc+i));
		return val(loc,TREF);
	}
	inline val arrreverse(ull ref){
		ull id=getarrid(ref);
		if(is_obj[id])fatal("object is not reverse-able%c",' ');
		ull loc=allocarr();
		vector<val>ret;
		for(auto a:indices[id])ret.push_back(generef(-a));
		reverse(ret.begin(),ret.end());
		for(uint i=0;i<ret.size();i++)generef(-(loc+i))=ret[i],mdfaddr(-(loc+i));
		return val(loc,TREF);
	}
	inline val arrpush(ull ref,const val&v){
		ull id=getarrid(ref);
		if(is_obj[id])fatal("can not push elements into an object reference%c",' ');
		ull addr=indices[id].size()?*indices[id].rbegin():ref;
		if(getlen(val(ref,TREF)))addr++;
		generef(-addr)=v,mdfaddr(-addr);
		return v;
	}
	inline val arrpop(ull ref){
		ull id=getarrid(ref);
		if(is_obj[id])fatal("can not pop elements from an object reference%c",' ');
		if(!indices[id].size())return val(0,TUNDEF);
		ull addr=*indices[id].rbegin();
		val ret=generef(-addr);
		mdfaddr(-addr,1);
		return ret;
	}
	inline val arrback(ull ref){
		ull id=getarrid(ref);
		if(is_obj[id])fatal("can not get back elements from an object reference%c",' ');
		if(!indices[id].size())return val(0,TUNDEF);
		ull addr=*indices[id].rbegin();
		val ret=generef(-addr);
		return ret;
	}
	inline val int2str(ull x,ull base){
		string r="";int n=0;
		if(x==0)return (string)"0";
		if(x<0)n=1,x=-x;
		if(abs(base)>36||abs(base)<=1)fatal("invalid number parsing base: %lld",base);
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
	inline val str2int(const string&x,ull base){
		ull r=0,n=0;
		if(abs(base)>36||abs(base)<=1)fatal("invalid number parsing base: %lld",base);
		uint i=0;
		if(x.size()&&x[0]=='-')n=1,i++;
		for(;i<x.size();i++){
			int v=0;char a=x[i];
			if(isdigit(a))v=a&15;
			else if(toupper(a)>='A'&&toupper(a)<=('A'+base-10-1))v=toupper(a)-'A'+10;
			else fatal("invalid string of base %lld: '%s'",base,x.c_str());
			r*=base,r+=v;
		}
		return r*(n?-1:1);
	}
	inline val utf8string(const vector<val>&v){
		string r="";
		if(v.size()==1&&v[0].type==TREF){
			ull id=getarrid(v[0].num);
			if(is_obj[id])fatal("invalid argument type for utf-8 string: [reference to an object]%c",' ');
			for(auto a:indices[id]){
				val v=generef(-a);
				if(v.type!=TNUM)fatal("invalid argument type for utf-8 string: %s(%s)",valtypename[(uint)v.type],v.tostr().c_str());
				r+=encd(v.num);
			}
		}
		else{
			for(auto a:v){
				if(a.type!=TNUM)fatal("invalid argument type for utf-8 string: %s(%s)",valtypename[(uint)a.type],a.tostr().c_str());
				r+=encd(a.num);
			}
		}
		return r;
	}
}
set<ull>stringing;
ull inner_stack[RUNSTACK_SIZE/32];
inline val call_op_func(const val&_this,const string&key,const val&arg){
	ull ref=_this.num;
	ull nr=newreg();generef(nr)=val(ref,TREF);
	vector<ull>arglist;
	if(arg.type!=TUNDEF){ull argr=newreg();generef(argr)=arg;arglist.push_back(argr);}
	return generef(call_func(generef(getaddr(val(ref,TREF),key)).num,arglist,inner_stack,nr));
}
inline string reftype(ull ref){
	ull id=getarrid(ref);
	if(is_obj[id]){
		if(hasfield(val(ref,TREF),val("__class__")).is_true())return generef(getaddr(val(ref,TREF),val("__class__"))).tostr();
		return "object";
	}
	return "Array";
}
inline val allkeys(ull ref){
	ull id=getarrid(ref);
	vector<val> ret;
	for(auto a:indices[id])ret.push_back(indexval(a%arrlength));
	ull loc=allocarr();
	for(uint i=0;i<ret.size();i++)generef(-(loc+i))=val(ret[i]),mdfaddr(-(loc+i));
	return val(loc,TREF);
}
inline val allvalues(ull ref){
	ull id=getarrid(ref);
	vector<val> ret;
	for(auto a:indices[id])ret.push_back(generef(-a));
	ull loc=allocarr();
	for(uint i=0;i<ret.size();i++)generef(-(loc+i))=val(ret[i]),mdfaddr(-(loc+i));
	return val(loc,TREF);
}
inline string ref2string(ull ref,int a){
	ull id=getarrid(ref);
	stringstream ret("");
	if(is_obj[id]){
		if(a&&hasfield(val(ref,TREF),val("to_str")).is_true()){
			ull nr=newreg();generef(nr)=val(ref,TREF);
			return generef(call_func(generef(getaddr(val(ref,TREF),val("to_str"))).num,vector<ull>(),inner_stack,nr)).tostr();
		}
		if(stringing.count(ref))return "{...}";
		stringing.insert(ref);
		ret<<"{";
		for(auto a:indices[id]){
			ret<<indexval(a%arrlength).tostr(1)<<":"<<generef(-a).tostr(1)<<", ";
		}
		string r=ret.str();
		if(r.size()>1)r.back()='}';
		else r.push_back('}');
		stringing.erase(stringing.find(ref));
		return r;
	}
	else{
		if(stringing.count(ref))return "[...]";
		stringing.insert(ref);
		ret<<"[";
		ull last=0;
		for(auto a:indices[id]){
			if(last!=0&&abs(a-last)>1)ret<<"<"<<abs(a-last)-1<<" empty "<<(abs(a-last)-1>1?"slots":"slot")<<">, ";
			ret<<generef(-a).tostr(1)<<", ";
			last=a;
		}
		string r=ret.str();
		if(r.size()>1)r.back()=']';
		else r.push_back(']');
		stringing.erase(stringing.find(ref));
		return r;
	}
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
				if(!isprint(a))r+="\\u00"+utils::int2str((unsigned char)a,16).str;
				else r+=a;
				break;
			}
		}
	}
	return "\""+r+"\"";
}
inline int call_builtin(const int&fid,const vector<ull>&args,ull this_obj){
	#define param(x) (args[args.size()-1-(x)])
	#define need(x)\
	do{if(args.size()<x)fatal("at least %d argument(s) needed when calling %d, %d given",x,fid,(uint)args.size());}while(0)
	#define must(x)\
	do{if(args.size()!=x)fatal("%d argument(s) needed when calling %d, %d given",x,fid,(uint)args.size());}while(0)
	val retv;
	#define arg(x) (generef(param(x)))
	#define valtype(x) (arg(x).type)
	#define chktype(x,t)\
	do{if(valtype(x)!=t)fatal("argument %d requires '%s' for %d, got '%s'",x,valtypename[t],fid,valtypename[valtype(x)]);}while(0)
	switch(fid){
		case 1:for(uint i=0;i<args.size();i++)cout<<arg(i).tostr()<<' ';cout<<endl;retv=args.size();break;
		case 2:need(1);chktype(0,TNUM);retv=arg(0);exit(arg(0).num);break;
		case 3:retv=file_manager::read_number();break;
		case 4:retv=file_manager::read_string();break;
		case 5:retv=file_manager::read_line();break;
		case 6:retv=file_manager::read_getchar();break;
		case 7:retv=file_manager::read_eof();break;
		case 8:need(1);chktype(0,TNUM);retv=sin(arg(0).num);break;
		case 9:need(1);chktype(0,TNUM);retv=cos(arg(0).num);break;
		case 10:need(1);chktype(0,TNUM);retv=tan(arg(0).num);break;
		case 11:need(1);chktype(0,TNUM);retv=asin(arg(0).num);break;
		case 12:need(1);chktype(0,TNUM);retv=acos(arg(0).num);break;
		case 13:need(1);chktype(0,TNUM);retv=atan(arg(0).num);break;
		case 14:need(2);chktype(0,TNUM);chktype(1,TNUM);retv=atan2(arg(0).num,arg(1).num);break;
		case 15:need(1);chktype(0,TNUM);retv=exp(arg(0).num);break;
		case 16:need(1);chktype(0,TNUM);retv=log(arg(0).num);break;
		case 17:{
			need(1);chktype(0,TSTR);
			if(args.size()==1)retv=file_manager::file_open(arg(0).str);
			else{chktype(1,TSTR);retv=file_manager::file_open(arg(0).str,arg(1).str);}
			break;
		}
		case 18:need(1);chktype(0,TNUM);retv=file_manager::fread_number(arg(0).num);break;
		case 19:need(1);chktype(0,TNUM);retv=file_manager::fread_string(arg(0).num);break;
		case 20:need(1);chktype(0,TNUM);retv=file_manager::fread_line(arg(0).num);break;
		case 21:need(1);chktype(0,TNUM);for(uint i=1;i<args.size();i++)file_manager::fwrite_string(arg(0).num,arg(i).tostr());retv=args.size();break;
		case 22:need(1);chktype(0,TNUM);retv=file_manager::file_close(arg(0).num);break;
		case 23:need(1);chktype(0,TNUM);retv=file_manager::file_eof(arg(0).num);break;
		case 24:retv=clock();break;
		case 25:need(1);chktype(0,TSTR);retv=system(arg(0).str.c_str());break;
		case 26:retv=1.0*rand()/RAND_MAX;break;
		case 27:need(1);chktype(0,TNUM);srand(arg(0).num);retv=arg(0);break;
		case 28:need(1);retv=getlen(arg(0));break;
		case 29:need(1);chktype(0,TSTR);retv=arg(0).str.size()?arg(0).str[0]:0;break;
		case 30:need(1);chktype(0,TNUM);retv=(string)""+char(arg(0).num);break;
		case 31:need(1);{chktype(0,TSTR);vector<val> vpr;for(uint i=1;i<args.size();i++)vpr.push_back(arg(i));retv=args.size();cout<<utils::fmtprint(arg(0).str,vpr)<<endl;break;}
		case 32:need(1);fatal(arg(0).tostr().c_str(),0);break;
		case 33:retv=utils::substring(generef(this_obj).str,args.size()>=1?arg(0):val(),args.size()>=2?arg(1):val());break;
		case 34:{vector<val> vpr;for(uint i=0;i<args.size();i++)vpr.push_back(arg(i));retv=utils::fmtprint(generef(this_obj).str,vpr);break;}
		case 35:need(1);chktype(0,TNUM);retv=utils::repeatstr(generef(this_obj).str,arg(0).num);break;
		case 36:need(2);chktype(0,TSTR);chktype(1,TSTR);retv=utils::replacestr(generef(this_obj).str,arg(0).str,arg(1).str);break;
		case 37:need(1);chktype(0,TSTR);retv=utils::splitstr(generef(this_obj).str,arg(0).str);break;
		case 38:need(1);chktype(0,TSTR);retv=utils::indexof(generef(this_obj).str,arg(0).str,args.size()>=2?arg(1):val());break;
		case 39:need(2);chktype(0,TNUM);chktype(1,TNUM);retv=utils::substr(generef(this_obj).str,arg(0).num,arg(1).num);break;
		case 40:case 41:retv=utils::changecase(generef(this_obj).str,fid&1);break;
		case 42:need(1);chktype(0,TSTR);retv=utils::startswith(generef(this_obj).str,arg(0).str)?val(TTRUE):val(TFALSE);break;
		case 43:need(1);chktype(0,TSTR);retv=utils::endswith(generef(this_obj).str,arg(0).str)?val(TTRUE):val(TFALSE);;break;
		case 44:retv=utils::trim(generef(this_obj).str);break;
		case 45:retv=utils::arrindices(generef(this_obj).num);break;
		case 46:retv=utils::arrsort(generef(this_obj).num);break;
		case 47:retv=utils::arrreverse(generef(this_obj).num);break;
		case 48:retv=getlen(val(generef(this_obj).num,TREF));break;
		case 49:need(1);retv=(string)valtypename[arg(0).type];break;
		case 50:must(1);retv=arg(0).tostr();break;
		case 51:must(1);chktype(0,TSTR&&valtype(0)!=TNUM);retv=str2num(arg(0).tostr());break;
		case 52:must(1);chktype(0,TSTR);retv=hex2dec(arg(0).str);break;
		case 53:must(1);chktype(0,TNUM);retv=dec2hex(arg(0).num);break;
		case 54:must(2);chktype(0,TNUM);chktype(1,TNUM);retv=utils::int2str(arg(0).num,arg(1).num);break;
		case 55:must(2);chktype(0,TSTR);chktype(1,TNUM);retv=utils::str2int(arg(0).str,arg(1).num);break;
		case 56:{vector<val> vpr;for(uint i=0;i<args.size();i++)vpr.push_back(arg(i));retv=utils::utf8string(vpr);break;}
		case 57:for(uint i=0;i<args.size();i++)retv=utils::arrpush(generef(this_obj).num,arg(i));break;
		case 58:retv=utils::arrpop(generef(this_obj).num);break;
		case 59:need(1);chktype(0,TNUM);retv=ceil(arg(0).num);break;
		case 60:need(1);chktype(0,TNUM);retv=floor(arg(0).num);break;
		case 61:need(1);chktype(0,TNUM);retv=log2(arg(0).num);break;
		case 62:need(1);retv=arg(0);for(uint i=1;i<args.size();i++)retv=max(retv,arg(i),[](const val&a,const val&b){return (a.smller(b)).is_true();});break;
		case 63:need(1);retv=arg(0);for(uint i=1;i<args.size();i++)retv=min(retv,arg(i),[](const val&a,const val&b){return (b.smller(a)).is_true();});break;
		case 64:need(1);retv=arg(0);for(uint i=1;i<args.size();i++)retv=retv+arg(i);break;
		case 65:need(1);chktype(0,TREF);retv=allkeys(arg(0).num);break;
		case 66:need(1);chktype(0,TREF);retv=allvalues(arg(0).num);break;
		case 67:retv=utils::arrback(generef(this_obj).num);break;
		default:fatal("unknown builtin function id %d\n",fid);retv=0;break;
	}
	int nr=newreg();generef(nr)=retv;
	return nr;
}
inline ull call_func(const int&fid,const vector<ull>&args,runstack stk_start,ull this_obj,uint this_type){
	if(builtin.find(fid)!=builtin.end())return call_builtin(fid,args,this_obj);
	const vector<int> &pid=functable[fid].pid;
	if(functable[fid].pid.size()<args.size())fatal("function at %d needs at most %lld argument(s), %lld given",fid,functable[fid].pid.size(),args.size());
	vector<val>ag;ag.resize(args.size());
	for(uint i=0;i<args.size();i++)ag[i]=generef(args[args.size()-1-i]);
	uint oldsize=frames.size();newframe();funcstack.push_back(fid);
	for(uint i=0;i<ag.size();i++)generef(pid[i],1)=ag[i];
	int ret=runbytes(functable[fid].instr,ag,fid,stk_start,this_obj,this_type);
	val v=generef(ret);
	while(oldsize<frames.size())delframe();funcstack.pop_back();
	int nr=newreg();
	return generef(nr)=v,nr;
}
bool inited;
inline val initarr(const string&name,const vector<val>&v){
	val vr=val(allocarr(),TREF);
	for(uint i=0;i<v.size();i++)generef(getaddr(vr,i))=v[i],mdfaddr(getaddr(vr,i));
	generef(getid(name))=vr;
	return vr;
}
inline val initarr(const string&name,const vector<val>&v,const vector<val>&id){
	val vr=val(allocarr(),TREF);
	for(uint i=0;i<v.size();i++)generef(getaddr(vr,id[i]))=v[i],mdfaddr(getaddr(vr,id[i]));
	generef(getid(name))=vr;
	return vr;
}
inline val initarr(const vector<val>&v,const vector<val>&id){
	val vr=val(allocarr(),TREF);
	for(uint i=0;i<v.size();i++)generef(getaddr(vr,id[i]))=v[i],mdfaddr(getaddr(vr,id[i]));
	return vr;
}
vector<val> cmdargs;
umap<string,vector<val>>clsvt;
umap<string,vector<val>>clsvr;
void initvm(){
	if(inited)return;inited=1;
	memset(vmstack,0,sizeof(vmstack)); 
	newframe(),funcstack.push_back(-1);
	int r;vector<val> vt,vr;
	#define makeobj(name) ({\
		for(auto a:vt)clsvt[name].push_back(a);\
		for(auto a:vr)clsvr[name].push_back(a);\
		vt.clear(),vr.clear();\
	})
	#define func(name) (r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid(name))=val(r,TFUNC))
	#define builtincls(type,name) (r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid(name))=val(r,TFUNC),builtinmethod[type][name]=getid(name))
	#define method(name) (r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),vt.push_back(val(r,TFUNC)),vr.push_back(val((string)name)))
	method("print");
	makeobj("Console");
	method("exit");
	makeobj("System"),
	method("read_number"),method("read_string"),method("read_line"),method("getchar"),method("eof");
	makeobj("Console");
	method("sin"),method("cos"),method("tan"),method("asin"),method("acos"),method("atan"),method("atan2"),method("exp"),method("log");
	vt.push_back(val(acos(-1))),vr.push_back((string)"pi");
	makeobj("Math");
	method("open"),method("read_number"),method("read_string"),method("read_line"),method("write"),method("close"),method("eof");
	makeobj("Fileio");
	method("clock"),method("system"),
	vt.push_back(initarr("#",cmdargs)),vr.push_back((string)"args");
	makeobj("System");
	method("random"),method("set_random_seed");
	makeobj("Math");
	func("len"),func("ascii"),func("char");
	generef(getid("credits"))=val(CREDITS);
	generef(getid("help"))=val(HELP);
	generef(getid("copyright"))=val(COPYRIGHT);
	generef(getid("license"))=val(LICENSE);
	method("printf");
	makeobj("Console");
	method("abort");
	makeobj("System");
	builtincls(TSTR,"substring"),builtincls(TSTR,"format"),builtincls(TSTR,"repeat");
	builtincls(TSTR,"replace"),builtincls(TSTR,"split"),builtincls(TSTR,"index");
	builtincls(TSTR,"substr"),builtincls(TSTR,"to_upper"),builtincls(TSTR,"to_lower");
	builtincls(TSTR,"starts_with"),builtincls(TSTR,"ends_with"),builtincls(TSTR,"trim");
	builtincls(TREF,"indice"),builtincls(TREF,"sort"),builtincls(TREF,"reverse"),builtincls(TREF,"length");
	func("type"),func("string"),func("number"),func("dec"),func("hex");
	func("int_to_str"),func("str_to_int"),func("utf8_string");
	builtincls(TREF,"push"),builtincls(TREF,"pop");
	method("ceil"),method("floor"),method("log2");
	makeobj("Math");
	func("max"),func("min"),func("sum");
	func("keys"),func("values");
	builtincls(TREF,"back");
	for(auto a:clsvt)initarr(a.first,clsvt[a.first],clsvr[a.first]);
	usedfuncs=1024;
	usedname=1024;
	object_manager::make_class("object","object",umap<string,val>(),umap<string,int>(),0);
	object_manager::make_class("Array","object",umap<string,val>(),umap<string,int>(),0);
	#undef func
	#undef method
	#undef makeobj
	#undef builtincls
}
}
namespace launcher{
	bool cmp,run;
	string str; 
	stringstream source;
	char src[1024*1024*2];
	void read_source(string);
	string replace_ext(string file){
		for(int i=file.size()-1;~i;i--)if(file[i]=='.')return file.substr(0,i)+".rbq6";
		return file+".rbq6";
	}
	inline void write2b(ofstream&fcout,int v){codeset g=loadshort(v);for(auto a:g)fcout<<a;}
	inline void write4b(ofstream&fcout,int v){codeset g=loadint(v);for(auto a:g)fcout<<a;}
	void savecode(const string&file,const codeset&s){
		ofstream fcout(file.c_str(),ios::binary);
		fcout.put(char(0x0f));
		fcout.put(char(0xf0));
		fcout.put(char(0x26));
		fcout.put(char(0x56));
		write4b(fcout,CURRENT_VERSION);
		fcout.put(char(force_short_double));
		write4b(fcout,num_pool.size());
		if(force_short_double)for(auto&n:num_pool){bpser8.x=n;for(int i=0;i<8;i++)fcout.put(char(bpser8.bits[i]));}
		else for(auto&n:num_pool){bpser.x=n;for(int i=0;i<16;i++)fcout.put(char(bpser.bits[i]));}
		write4b(fcout,str_pool.size());
		for(auto&a:str_pool){
			write4b(fcout,a.size());
			for(auto v:a)fcout.put(char(v));
		}
		write4b(fcout,func_pool.size());
		for(auto&f:func_pool){
			write2b(fcout,f.pid.size());
			write4b(fcout,f.instr.size());
			write2b(fcout,f.upvs.size());
			for(auto&p:f.pid)write2b(fcout,p);
			for(auto a:f.instr)fcout.put((char)a);
			for(auto&u:f.upvs)write2b(fcout,u);
		}
		for(auto a:s)fcout.put((char)a);
		fcout.close(); 
	}
	char mulline=0;
	bool not_multiline(const string&s){
		for(uint i=0;i+2<s.size();i++){
			if(mulline!=0){
				if(s[i]==mulline&&s[i+1]==mulline&&s[i+2]==mulline)mulline=0,i+=2;
			}
			else{
				if((s[i]=='\''||s[i]=='\"')&&s[i+1]==s[i]&&s[i+2]==s[i])mulline=s[i],i+=2;
			}
		}
		return !mulline;
	}
	bool chkprecmd(const string&s){
		if(not_multiline(s)&&s[0]=='#'){
			string t;stringstream ss("");ss<<s.substr(1);
			vector<string> vs;while(ss>>t)vs.push_back(t);
			if(vs[0]=="include")read_source(vs[1]);
			else fatal("unknown command line %s",vs[0].c_str());
			return 1;
		}
		else return 0;
	}
	void read_source(string file){
		try{
			if(file[0]=='\"'||file[0]=='\'')file=file.substr(1,file.size()-2);
			ifstream fcin(file);
			if(!fcin){fatal("can not open file '%s'",file.c_str());return;}
			while(getline(fcin,str)){
				if(chkprecmd(str));
				else source<<str<<endl;
			}
		}
		catch(string &s){
			cout<<s<<endl;
		}
	}
	void cli(){
		try{new_scope(),vm::initvm();}catch(string&s){cout<<s<<endl;exit(0);}
		cout<<fixed<<setprecision(12)<<"RBQ 6.0\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information."<<endl;
		cout<<">>> ";
		while(getline(cin,str)){
		try{
			toks.clear(),curtok=0;
			for(uint i=0;i<str.size();i++)src[i]=str[i];src[str.size()]='\0';
			tokenize(src);codeset c;
			while(curtok<toks.size())concat(c,compile());
			if(c.size()&&c[c.size()-1]==POP)c[c.size()-1]=RETURN;
			cout<<vm::generef(vm::runbytes(c,vector<vm::val>(),-1,vm::vmstack)).tostr(1)<<endl;
		}catch(string&s){cout<<s<<endl;}
			cout<<">>> ";
		}
	}
	vector<string> files;
	void apply_argv(char *arg){
		uint len=strlen(arg);
		if(arg[0]=='-')for(uint i=1;i<len;i++)arg[i]=tolower(arg[i]),cmp=cmp||arg[i]=='c',run=run||arg[i]=='r',force_short_double=force_short_double||arg[i]=='d';
		else files.push_back(arg);
	}
	void start_compile2(){
		new_scope(),vm::initvm();
		static codeset c;
		static string str=source.str();
		memset(src,0,sizeof(src)),curtok=0;
		for(uint i=0;i<str.size();i++)src[i]=str[i];src[str.size()]='\0';
		toks.clear(),tokenize(src);
		while(curtok<toks.size())concat(c,compile());
		files[0]=replace_ext(files[0]);
		savecode(files[0],c);
	}
	string start_compile(){
		if(!files.size())fatal("need at least one input source file to compile%c",' ');
		for(auto a:files)read_source(a);
		start_compile2();
		return files[0];
	}
	inline int read2b(ifstream&fcin){int g=fcin.get()*0xff;g+=fcin.get();return g;}
	inline int read4b(ifstream&fcin){int g=fcin.get()*0xffffff;g+=fcin.get()*0xffff;g+=fcin.get()*0xff;g+=fcin.get();return g;}
	void run_rbq(string arg){
		if(!arg.size())fatal("need a bytecode file to run%c",' ');
		new_scope(),vm::initvm();codeset s;
		ifstream fcin(arg.c_str(),ios::binary);
		if(!fcin)fatal("can not open bytefile '%s'",arg.c_str()); 
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
				while(r--)v+=fcin.get();str_pool.push_back(v);
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
		vm::runbytes(s,vector<vm::val>(),-1,vm::vmstack);
	}
}
signed main(signed argc,char **argv){
	for(int i=0;i<argc;i++)vm::cmdargs.push_back(vm::val((string)argv[i]));
	if(argc<=1)launcher::cli();
	else if(argc==2&&argv[1][0]!='-')try{launcher::run_rbq(argv[1]);}catch(string &s){cout<<s<<endl;}
	else{
		try{
			for(int i=1;i<argc;i++)launcher::apply_argv(argv[i]);
			string r="";
			if(launcher::cmp)r=launcher::start_compile();
			if(launcher::run)launcher::run_rbq(r);
		}
		catch(string &s){cout<<s<<endl;}
	}
	return 0;
}
