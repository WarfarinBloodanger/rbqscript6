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
OPCODE JUMP_IF_TRUE=0XEB;
OPCODE SEEK=0XFF;
OPCODE BREAKHOLDER=0XF0;
OPCODE CTNHOLDER=0XF1; 
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
	TOK_FUNC,TOK_IF,TOK_ELSE,TOK_WHILE,TOK_RET,TOK_FOR,TOK_VAR,TOK_BREAK,TOK_CTN,
	TOK_TRUE,TOK_FALSE,TOK_NULL,TOK_UNDEFINED,TOK_INCLUDE,TOK_THIS
};
const char* tokenname[]={
	"number","string","identifier","hexnumber",
	"'+'","'-'","'*'","'/'","'%'","'=='","'!='","'>'","'<'","'>='","'<='",
	"'&&'","'||'","'!'","'&'","'|'","'~'","'^'","'<<'","'>>'",
	"','","'='","'.'","'?'","':'","'('","')'","'['","']'","'{'","'}'","';'",
	"'function'","'if'","'else'","'while'","'return'","'for'","'local'","'break'","'continue'",
	"'true'","'false'","'null'","'undefined'","'include'","'this'"
};
inline int prior(char tok){
	switch(tok){
		case TOK_COM:return 10;
		case TOK_ASS:return 20;
		case TOK_OR:return 30;
		case TOK_AND:return 40;
		case TOK_BITOR:return 50;
		case TOK_XOR:return 60;
		case TOK_BITAND:return 70;
		case TOK_EQL:case TOK_NEQ:return 80;
		case TOK_LE:case TOK_SML:case TOK_GE:case TOK_BIG:return 90;
		case TOK_LSHF:case TOK_RSHF:return 100;
		case TOK_ADD:case TOK_SUB:return 110;
		case TOK_MUL:case TOK_DIV:case TOK_MOD:return 120;
		case TOK_NOT:case TOK_BITNOT:return 130;
		case TOK_LPR:case TOK_LBK:case TOK_DOT:return 140; 
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
	if(s=="true")return TOK_TRUE;
	if(s=="false")return TOK_FALSE;
	if(s=="null")return TOK_NULL;
	if(s=="undefined")return TOK_UNDEFINED;
	if(s=="include")return TOK_INCLUDE;
	if(s=="this")return TOK_THIS;
	return TOK_ID; 
}
void tokenize(char *src){
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
			char s=src[loc];cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			while(loc<len&&src[loc]!=s&&src[loc]!='\r'&&src[loc]!='\n'){
				if(src[loc]=='\\')cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			}
			if(src[loc]==s)cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			cur.type=TOK_STR,toks.push_back(cur);
		}
		else if(isspace(src[loc]))(chkln,loc++,loc-1);
		else switch(src[loc]){
			case('+'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_ADD,toks.push_back(cur);break;
			case('-'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_SUB,toks.push_back(cur);break;
			case('*'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_MUL,toks.push_back(cur);break;
			case('/'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_DIV,toks.push_back(cur);break;
			case('%'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_MOD,toks.push_back(cur);break;
			case('.'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_DOT,toks.push_back(cur);break;
			case('('):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LPR,toks.push_back(cur);break;
			case('['):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LBK,toks.push_back(cur);break;
			case('{'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LBR,toks.push_back(cur);break;
			case(')'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RPR,toks.push_back(cur);break;
			case(']'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RBK,toks.push_back(cur);break;
			case('}'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RBR,toks.push_back(cur);break;
			case('^'):cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_XOR,toks.push_back(cur);break;
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
				else if(loc<len&&src[loc]=='>')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_RSHF;
				else cur.type=TOK_BIG;
				toks.push_back(cur);
				break;
			}
			case('<'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='=')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LE;
				else if(loc<len&&src[loc]=='<')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_LSHF;
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
				else cur.type=TOK_BITAND;
				toks.push_back(cur);
				break;
			}
			case('|'):{
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				if(loc<len&&src[loc]=='|')cur.val.push_back(src[loc]),(chkln,loc++,loc-1),cur.type=TOK_OR;
				else cur.type=TOK_BITOR;
				toks.push_back(cur);
				break;
			}
			default:fatal("unknown char '%c' at line %d, column %d",src[loc],line,column);(chkln,loc++,loc-1);break;
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
struct bitparse{
	union{
		double x;
		uchar bits[8];
		ull n;
	};
};
bitparse bpser;
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
char buf[24];
string num2str(const double&d){
	sprintf(buf,"%.14g",d);return buf;
}
inline void concat(codeset &a,const codeset &b){
	for(auto x:b)a.push_back(x);
} 
codeset compile_num(double x){
	codeset s;
	bpser.x=x;
	s.push_back(LOADNUM);
	for(int i=0;i<8;i++)s.push_back(bpser.bits[i]);
	return s;
}
inline codeset loadshort(int v){
	codeset s;s.push_back(v/0xffu),s.push_back(v%0xffu);return s;
} 
inline codeset loadint(int v){
	codeset s;concat(s,loadshort(v/0xffffu)),concat(s,loadshort(v%0xffffu));return s;
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
codeset compile_str(const string&x){
	codeset s,b;
	uint len=x.size()-1,c=0;
	s.push_back(LOADSTR);
	concat(s,loadint(0));
	#define gen(x) s.push_back(x/0xfu);s.push_back(x%0xfu);
	for(uint i=1;i<len;i++)if(x[i]=='\\'){
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
					for(auto v:e){gen(v);}
					i+=2,c+=e.size()-1; 
					break;
				}
				default:fatal("unknown escaped char '\\%c' in string '%s'",x[i+1],x.c_str());
			}
			i++,c++;
		}
	}else {
		gen(x[i]);c++;
	}
	b=loadint(c);
	s[1]=b[0],s[2]=b[1],s[3]=b[2],s[4]=b[3];
	return s;
}
codeset compile();
codeset compile_block(bool a=1);
codeset compile_upvalue(string);
codeset parse_args(char,uint&);
codeset parse_params(uint&);
codeset parse_decl();
codeset parse_obj();
int anfunc=0;
inline string anonyfunc(){return "$"+num2str(++anfunc);}
codeset parse_expr(int precd){
	codeset s,b1,b2;uint tmp;bool liter=precd==prior(TOK_DOT)&&(curtok-1>=0&&toks[curtok-1].type==TOK_DOT);
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
		chklit_strict(TOK_IF,"if");
		chklit_strict(TOK_ELSE,"else");
		chklit_strict(TOK_WHILE,"while");
		chklit_strict(TOK_RET,"return");
		chklit_strict(TOK_FOR,"for");
		chklit_strict(TOK_BREAK,"break");
		chklit_strict(TOK_CTN,"continue");
		chklit_strict(TOK_INCLUDE,"include");
		case TOK_VAR:{
			if(liter)concat(s,compile_str("var")),readtok(TOK_VAR),s.push_back(GETADDR);
			else fatal("'var' should not appear at line %d, column %d",tok.line,tok.column);
			break;
		}
		case TOK_ID:{
			if(liter)concat(s,compile_str('"'+tok.val+'"')),readtok(TOK_ID),s.push_back(GETADDR);
			else s.push_back(LOADVAR),concat(s,loadint(getid(tok.val))),readtok(TOK_ID);
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
		case TOK_FUNC:{
			if(liter)concat(s,compile_str("function")),readtok(TOK_FUNC),s.push_back(GETADDR);
			else{
				string f=anonyfunc();
				readtok(TOK_FUNC);s.push_back(LOADFUNC);
				new_scope();
				readtok(TOK_LPR);b1=parse_params(tmp),readtok(TOK_RPR);
				concat(s,loadint(tmp));
				readtok(TOK_LBR);b2=compile_block(0);readtok(TOK_RBR);
				b2.push_back(LOADUNDEFINED),b2.push_back(RETURN);
				concat(s,loadint(b2.size()));
				concat(s,loadint(used_upvalues[used_upvalues.size()-1].size()));
				concat(s,b1),concat(s,compile_upvalue(f)),concat(s,b2);
				del_scope();
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
			case TOK_QUEZ:{
				readtok(TOK_QUEZ);
				b1=parse_expr(prior(TOK_QUEZ));
				readtok(TOK_COL);
				b2=parse_expr(prior(TOK_QUEZ));
				s.push_back(JUMP_IF_FALSE);
				concat(s,loadint(b1.size()));
				s.push_back(JUMP);
				concat(s,loadint(b2.size()));
				break;
			}
			case TOK_OR:{
				v=tok.val,pr=prior(tok.type);curtok++;
				b1=parse_expr(pr); 
				s.push_back(OR);
				concat(s,loadint(b1.size()));
				concat(s,b1);
				break;
			}
			case TOK_AND:{
				v=tok.val,pr=prior(tok.type);curtok++;
				b1=parse_expr(pr); 
				s.push_back(AND);
				concat(s,loadint(b1.size()));
				concat(s,b1);
				break;
			}
			case TOK_BITOR:PF(BITOR);
			case TOK_BITAND:PF(BITAND);
			case TOK_XOR:PF(XOR);
			case TOK_EQL:PF(EQL);
			case TOK_NEQ:PF(NEQ);
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
				s.push_back(CALL);concat(s,loadint(argcnt));
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
codeset parse_params(uint &c){
	codeset s;c=0;
	while(tok.type!=TOK_RPR){
		if(tok.type==TOK_AND)readtok(TOK_AND);
		concat(s,loadint(getid(readtok(TOK_ID).val,1)));
		c++;
		if(tok.type==TOK_COM)readtok(TOK_COM); 
	}
	return s;
}
codeset parse_decl(){
	codeset s;
	while(tok.type==TOK_ID){
		token t=readtok(TOK_ID);
		s.push_back(LOADVARLOCAL);
		concat(s,loadint(getid(t.val,1)));
		if(tok.type==TOK_ASS)readtok(TOK_ASS),concat(s,parse_expr(20));
		else s.push_back(LOADNULL);
		s.push_back(ASSIGNLOCAL);
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
codeset compile_func();
codeset compile_hold(uchar);
codeset compile(){
	codeset s;
	switch(tok.type){
		case TOK_IF:readtok(TOK_IF);concat(s,compile_if());break; 
		case TOK_LBR:readtok(TOK_LBR);concat(s,compile_block());readtok(TOK_RBR);break;
		case TOK_WHILE:readtok(TOK_WHILE);concat(s,compile_while());break;
		case TOK_RET:readtok(TOK_RET);concat(s,parse_expr(0));s.push_back(RETURN);break;
		case TOK_FOR:readtok(TOK_FOR);concat(s,compile_for());break;
		case TOK_FUNC:{
			if(curtok+1<toks.size()&&toks[curtok+1].type==TOK_ID){
				readtok(TOK_FUNC),concat(s,compile_func()),s.push_back(POP);
			}
			else concat(s,parse_expr(0));s.push_back(POP);break;
			break;
		}
		case TOK_BREAK:readtok(TOK_BREAK);concat(s,compile_hold(BREAKHOLDER));break;
		case TOK_CTN:readtok(TOK_CTN);concat(s,compile_hold(CTNHOLDER));break;
		case TOK_VAR:readtok(TOK_VAR),concat(s,parse_decl());break;
		default:concat(s,parse_expr(0));s.push_back(POP);break;
	}
	if(tok.type==TOK_FEN)readtok(TOK_FEN);
	return s;
}
void fillholder(codeset&s,const uint&led){
	codeset b;
	for(uint i=0;i+8<s.size();i++){
		if(
			s[i]==BREAKHOLDER&&s[i+1]==BREAKHOLDER&&s[i+2]==BREAKHOLDER&&
			s[i+3]==BREAKHOLDER&&s[i+4]==BREAKHOLDER&&s[i+5]==BREAKHOLDER&&
			s[i+6]==BREAKHOLDER&&s[i+7]==BREAKHOLDER&&s[i+8]==BREAKHOLDER
		){
			uint offset=s.size()-i-5;
			s[i]=JUMP,b=loadint(offset);
			s[i+1]=b[0],s[i+2]=b[1],s[i+3]=b[2],s[i+4]=b[3];
			s[i+5]=NOP,s[i+6]=NOP,s[i+7]=NOP,s[i+8]=NOP;
		}
		if(
			s[i]==CTNHOLDER&&s[i+1]==CTNHOLDER&&s[i+2]==CTNHOLDER&&
			s[i+3]==CTNHOLDER&&s[i+4]==CTNHOLDER&&s[i+5]==CTNHOLDER&&
			s[i+6]==CTNHOLDER&&s[i+7]==CTNHOLDER&&s[i+8]==CTNHOLDER
		){
			uint offset=i+1;
			s[i]=LOOP,b=loadint(offset);
			s[i+1]=b[0],s[i+2]=b[1],s[i+3]=b[2],s[i+4]=b[3];
			s[i+5]=NOP,s[i+6]=NOP,s[i+7]=NOP,s[i+8]=NOP;
		}
	}
}
codeset compile_block(bool frame){
	codeset s;
	if(frame)s.push_back(NEWFRAME);
	while(tok.type!=TOK_RBR)concat(s,compile());
	if(frame)s.push_back(DELFRAME);
	return s;
}
codeset compile_if(){
	codeset s=parse_expr(0);
	codeset b1=compile();
	codeset b2=codeset();
	if(tok.type==TOK_ELSE)readtok(TOK_ELSE),b2=compile();
	b1.push_back(JUMP);
	concat(b1,loadint(b2.size()));// IMPORTNAT
	s.push_back(JUMP_IF_FALSE);
	concat(s,loadint(b1.size()));
	concat(s,b1);
	concat(s,b2);
	return s;
}
codeset compile_while(){
	codeset s=parse_expr(0);
	codeset b=compile();
	s.push_back(JUMP_IF_FALSE);
	b.push_back(LOOP);
	concat(b,loadint(b.size()+s.size()+4));//IMPORTANT
	concat(s,loadint(b.size()));
	concat(s,b);
	fillholder(s,b.size());
	return s;
}
codeset compile_for(){
	readtok(TOK_LPR);
	codeset s=parse_expr(0);
	s.push_back(POP);
	codeset expr=parse_expr(0);
	codeset step=parse_expr(0);
	step.push_back(POP);
	readtok(TOK_RPR);
	codeset b=compile();
	concat(s,expr);
	s.push_back(JUMP_IF_FALSE);
	concat(b,step);
	b.push_back(LOOP);
	concat(b,loadint(b.size()+expr.size()+5));//IMPORTANT
	concat(s,loadint(b.size()));
	concat(s,b); 
	fillholder(s,b.size());
	return s;
}
codeset compile_upvalue(string fid){
	codeset s;
	for(auto a:used_upvalues[used_upvalues.size()-1])concat(s,loadint(a));
	return s;
}
codeset compile_func(){
	codeset s,b1,b2;
	string name=readtok(TOK_ID).val;
	uint tmp;
	s.push_back(LOADVAR);
	concat(s,loadint(getid(name)));
	new_scope();
	s.push_back(LOADFUNC);
	readtok(TOK_LPR);b1=parse_params(tmp),readtok(TOK_RPR);
	concat(s,loadint(tmp));
	readtok(TOK_LBR);b2=compile_block(0);readtok(TOK_RBR);
	b2.push_back(LOADUNDEFINED),b2.push_back(RETURN);
	concat(s,loadint(b2.size()));
	concat(s,loadint(used_upvalues[used_upvalues.size()-1].size()));
	concat(s,b1),concat(s,compile_upvalue(name)),concat(s,b2);
	del_scope();
	s.push_back(ASSIGN);
	return s;
}
codeset compile_hold(uchar h){
	codeset s;
	s.push_back(h),s.push_back(h),s.push_back(h),
	s.push_back(h),s.push_back(h),s.push_back(h),
	s.push_back(h),s.push_back(h),s.push_back(h);
	return s;
}
namespace vm{
const uint MAX_FILE_CNT=1024*4;
const uint RUNSTACK_SIZE=1024*1024;
typedef enum {TNUM,TSTR,TNULL,TFUNC,TREF,TTRUE,TFALSE,TUNDEF} valtype;
const char* valtypename[]={"number","string","null","function","reference","true","false","undefined"};
inline string ref2string(ull);
inline string strictstr(const string&);
struct val{
	double num;
	string str;
	uchar type;
	val(){type=TUNDEF;}
	val(const double &x){type=TNUM,num=x;}
	val(const string &s){type=TSTR,str=s;}
	static val maketrue(){val v;v.type=TTRUE;return v;}
	static val makefalse(){val v;v.type=TFALSE;return v;}
	val(valtype t){type=t;}
	val(int64_t ref,valtype t){type=t,num=ref;}
	bool is_true()const{return !(type==TFALSE||type==TNULL||(type==TNUM&&num==0));}
	string tostr(int strict=0)const{
		switch(type){
			case TNUM:return num2str(num);
			case TSTR:return strict?strictstr(str):str;
			case TTRUE:case TFALSE:return type==TTRUE?"true":"false";
			case TREF:return ref2string((ull)num);
			case TFUNC:return "<func "+num2str(num)+">";
			case TNULL:return "null";
			case TUNDEF:return "undefined";
		}
		return "?";
	}
	val operator+(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return num+b.num;
		if(type==TSTR&&b.type==TSTR)return str+b.str;
		if(type==TSTR||b.type==TSTR)return tostr()+b.tostr();
		fatal("operation '+' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#define math_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num;\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	math_method(-)
	math_method(*)
	math_method(/)
	val operator%(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return fmod(num,b.num);
		fatal("operation '%%' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#undef math_method
	#define int_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return (ull)num v (ull)b.num;\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	int_method(|)
	int_method(&)
	int_method(^)
	int_method(<<)
	int_method(>>)
	#undef int_method
	val operator<(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return (ull)num<(ull)b.num?maketrue():makefalse();
		if(type==TSTR&&b.type==TSTR)return str<b.str?maketrue():makefalse();
		fatal("operation '<' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());
		return val(TFALSE);
	}
	#define bool_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num?maketrue():makefalse();\
		fatal("operation '"#v"' can't be applied between '%s'(%s) and '%s'(%s)",valtypename[type],this->tostr().c_str(),valtypename[b.type],b.tostr().c_str());\
		return val(TFALSE);\
	}
	bool_method(<=)
	bool_method(>)
	bool_method(>=)
	val operator==(const val&b)const{
		if(type!=b.type)return val(TFALSE);
		if(type==TSTR)return str==b.str?maketrue():makefalse();
		return num==b.num?maketrue():makefalse();
	}
	val operator!=(const val&b)const{
		return ((*this)==b).is_true()?makefalse():maketrue();
	}
	#undef bool_method
	val operator+()const{
		if(type==TNUM)return +num;
		fatal("unary operation '+' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	val operator-()const{
		if(type==TNUM)return -num;
		fatal("unary operation '-' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	val operator~()const{
		if(type==TNUM)return ~(ull)num;
		fatal("unary operation '~' can't be applied on '%s'(%s)",valtypename[type],this->tostr().c_str());
		return val(TFALSE);
	}
	#define logic_method(v)\
	val operator v (const val&b)const{\
		return is_true() v b.is_true()?maketrue():makefalse();\
	}
	logic_method(&&)
	logic_method(||)
	val operator!()const{return !is_true()?maketrue():makefalse();}
	#undef logic_method
	val smller(const val&v)const{
		if(v.type!=type)return false;
		switch(type){
			case TNUM:return num<v.num?maketrue():makefalse();
			case TSTR:return str<v.str?maketrue():makefalse();
			default:return type<v.type?maketrue():makefalse();
		}
		return makefalse();
	}
};
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
inline ull allocarr(){return arrlength*(++usedarrs);}
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
umap<char,umap<string,ull>> builtinmethod;
inline int builtin_method(char type,const string&s,ull&r){
	if(builtinmethod[type].find(s)!=builtinmethod[type].end())return r=builtinmethod[type][s],1;
	return 0;
}
inline ull getaddr(const val&addr,const val&offset){
	ull r=0;
	if(addr.type==TSTR&&offset.type==TNUM){generef(r=newreg())=val((addr.str.size()>offset.num?((string)"")+addr.str[int(offset.num)]:""));return r;}
	else if(addr.type==TREF&&offset.type==TNUM)return(-(addr.num+offset.num));
	else if(addr.type==TREF&&offset.type==TSTR){
		if(builtin_method(addr.type,offset.str,r))return r;
		return(-(addr.num+getkeyhash(offset.str)));
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
int call_func(const int&fid,const vector<ull>&args,runstack stk_start,ull this_obj=0);
int runbytes(const codeset&s,runstack stk_start,ull this_obj=0){
	uint ip=0,len=s.size();
	runstack curstk=stk_start;
	stack<ull>cur_this_obj;
	#define BACK\
	ip++;\
	goto DECODE
	while(ip<len){
		DECODE:
		switch(s[ip]){
			default:{
				fatal("unknown bytecode %02X at position %d",s[ip],ip);
				BACK;
			}
			case LOADSTR:{
				string str="";
				ip++;
				uint id=(s[ip]<<24ull)+(s[ip+1]<<16ull)+(s[ip+2]<<8ull)+s[ip+3];
				ip+=3;
				uchar v=0;
				while(id--)v=s[ip+1]*0xfu+s[ip+2],ip+=2,str.push_back(v);
				*curstk=newreg();
				generef(*curstk)=val(str),curstk++;
				BACK;
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
			case LOADVAR:case LOADVARLOCAL:{
				ip++;
				uint id=(s[ip]<<24ull)+(s[ip+1]<<16ull)+(s[ip+2]<<8ull)+s[ip+3];
				ip+=3;
				*curstk=id,curstk++;
				BACK;
			}
			case ASSIGN:case ASSIGNLOCAL:{
				generef(*(curstk-2),s[ip]==ASSIGNLOCAL)=generef(*(curstk-1)),mdfaddr(*(curstk-2));
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
				BACK;
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
				ip+=7;
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
			MATH(BITAND,&);
			MATH(BITOR,|);
			MATH(LSHF,<<);
			MATH(RSHF,>>);
			MATH(XOR,^);
			case AND:{
				ip++;
				uint offset=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=3;
				bool cond=generef(*(curstk-1)).is_true();
				if(!cond)ip+=offset;
				else{
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				BACK;
			}
			case OR:{
				ip++;
				uint offset=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=3;
				bool cond=generef(*(curstk-1)).is_true();
				if(cond)ip+=offset;
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
			#undef UNARY
			case LOADARR:{
				ip++;
				int len=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
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
				ull len=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
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
				ull nr=getaddr(generef(*(curstk-2)),generef(*(curstk-1)));
				cur_this_obj.push(*(curstk-2));
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
				BACK;
			}
			case LOADFUNC:{
				ip++;
				uint pcnt=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=4;
				uint size=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=4;
				uint upvcnt=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=4;
				ull nr=newreg();
				vector<int> pid,upvs;codeset instr;
				while(pcnt--)pid.push_back((s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3]),ip+=4;
				while(upvcnt--)upvs.push_back((s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3]),ip+=4;
				while(size--)instr.push_back(s[ip]),ip++;
				ip--;
				ull fid=newfunc(pid,instr,upvs);
				generef(nr)=val(fid,TFUNC);
				*curstk=nr,curstk++;
				BACK;
			}
			case CALL:{
				ip++;
				uint argscnt=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=3;
				vector<ull> args,freelist;
				while(argscnt--){
					args.push_back(*(curstk-1));
					if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
					curstk--;
				}
				if(generef(*(curstk-1)).type!=TFUNC)fatal("can't call a non-function type '%s'(%s)",valtypename[generef(*(curstk-1)).type],generef(*(curstk-1)).tostr().c_str());
				
				ull fid=generef(*(curstk-1)).num;
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
				curstk--;
				ull nr=call_func(fid,args,curstk,cur_this_obj.size()?cur_this_obj.top():0);cur_this_obj.size()?cur_this_obj.pop():void();*curstk=nr,curstk++;
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
				uint offset=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=3+offset;
				BACK;
			}
			case JUMP_IF_FALSE:{
				ip++;
				uint offset=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip+=3;
				bool cond=generef(*(curstk-1)).is_true();
				if((unsigned int64_t)*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
				if(!cond)ip+=offset;
				BACK;
			}
			case LOOP:{
				ip++;
				uint offset=(s[ip]<<24ull)^(s[ip+1]<<16ull)^(s[ip+2]<<8ull)^s[ip+3];
				ip-=1+offset;
				BACK;
			}
			case LOADTHIS:{
				if(this_obj==0)fatal("'this' should not appear in non-objective-functions%c",' ');
				*curstk=this_obj,curstk++;
				BACK;
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
	inline void fwrite_number(int handle,double x){check_handle(handle);fprintf(file_ptrs[handle],"%.14g",x);fflush(file_ptrs[handle]);}
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
		addr++,generef(-addr)=v,mdfaddr(-addr);
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
inline string ref2string(ull ref){
	ull id=getarrid(ref);
	stringstream ret("");
	if(is_obj[id]){
		if(stringing.count(ref))return "{...}";
		stringing.insert(ref);
		ret<<"{";
		for(auto a:indices[id]){
			ret<<indexval(a%arrlength).tostr(1)<<":"<<generef(-a).tostr(1)<<",";
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
			if(last!=0&&abs(a-last)>1)ret<<"<"<<abs(a-last)-1<<" empty "<<(abs(a-last)-1>1?"slots":"slot")<<">,";
			ret<<generef(-a).tostr(1)<<",";
			last=a;
		}
		string r=ret.str();
		if(r.size()>1)r.back()=']';
		else r.push_back(']');
		stringing.erase(stringing.find(ref));
		return "Array "+r;
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
		default:fatal("unknown builtin function id %d\n",fid);retv=0;break;
	}
	int nr=newreg();generef(nr)=retv;
	return nr;
}
inline int call_func(const int&fid,const vector<ull>&args,runstack stk_start,ull this_obj){
	if(builtin.find(fid)!=builtin.end())return call_builtin(fid,args,this_obj);
	const vector<int> &pid=functable[fid].pid;
	if(functable[fid].pid.size()<args.size())fatal("function at %d needs at most %lld argument(s), %lld given",fid,functable[fid].pid.size(),args.size());
	vector<val>ag;ag.resize(args.size());
	for(uint i=0;i<args.size();i++)ag[i]=generef(args[args.size()-1-i]);
	uint oldsize=frames.size();newframe();funcstack.push_back(fid);
	for(uint i=0;i<ag.size();i++)generef(pid[i],1)=ag[i];
	int ret=runbytes(functable[fid].instr,stk_start,this_obj);
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
	for(auto a:clsvt)initarr(a.first,clsvt[a.first],clsvr[a.first]);
	usedfuncs=1024;
	usedname=1024;
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
	void savecode(const string&file,const codeset&s){
		ofstream fcout(file.c_str(),ios::binary);
		for(auto a:s)fcout.put((char)a);
		fcout.close(); 
	}
	bool chkinclude(){
		if(tok.type==TOK_INCLUDE){readtok(TOK_INCLUDE),readtok(TOK_STR),read_source(toks[curtok-1].val);return 1;}
		else return 0;
	}
	void read_source(string file){
		try{
			if(file[0]=='\"'||file[0]=='\'')file=file.substr(1,file.size()-2);
			ifstream fcin(file);
			if(!fcin){fatal("can not open file '%s'",file.c_str());return;}
			while(getline(fcin,str)){
				for(uint i=0;i<str.size();i++)src[i]=str[i];src[str.size()]='\0';
				toks.clear();tokenize(src),curtok=0;
				if(chkinclude());
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
			cout<<vm::generef(vm::runbytes(c,vm::vmstack)).tostr(1)<<endl;
		}catch(string&s){cout<<s<<endl;}
			cout<<">>> ";
		}
	}
	vector<string> files;
	void apply_argv(char *arg){
		uint len=strlen(arg);
		if(arg[0]=='-')for(uint i=1;i<len;i++)arg[i]=tolower(arg[i]),cmp=cmp||arg[i]=='c',run=run||arg[i]=='r';
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
		start_compile2();return files[0];
	}
	void run_rbq(string arg){
		if(!arg.size())fatal("need a bytecode file to run%c",' ');
		new_scope(),vm::initvm();codeset s;
		ifstream fcin(arg.c_str(),ios::binary);
		if(!fcin)fatal("can not open bytefile '%s'",arg.c_str()); 
		char c;while(fcin.get(c))s.push_back((uchar)c);
		vm::runbytes(s,vm::vmstack);
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
