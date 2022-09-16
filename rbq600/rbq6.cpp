#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef uint64_t ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef const uchar OPCODE;
struct hasher{
	size_t operator()(const int&x)const{return x;}
	size_t operator()(const uint&x)const{return x;}
};
const string HELP = "See [https://github.com/WarfarinBloodanger/rbqscript6].";
const string COPYRIGHT = "See [https://github.com/WarfarinBloodanger/rbqscript6] or send email to arknightswarfarin@163.com for more.";
const string CREDITS = "See [https://github.com/WarfarinBloodanger/rbqscript6].";
const string LICENSE = "See [https://github.com/WarfarinBloodanger/rbqscript6]. GNU 3.0 License is used.";
#define umap gp_hash_table
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
	TOK_TRUE,TOK_FALSE,TOK_NULL,TOK_UNDEFINED,TOK_INCLUDE
};
const char* tokenname[]={
	"number","string","identifier","hexnumber",
	"'+'","'-'","'*'","'/'","'%'","'=='","'!='","'>'","'<'","'>='","'<='",
	"'&&'","'||'","'!'","'&'","'|'","'~'","'^'","'<<'","'>>'",
	"','","'='","'.'","'?'","':'","'('","')'","'['","']'","'{'","'}'","';'",
	"'function'","'if'","'else'","'while'","'return'","'for'","'local'","'break'","'continue'",
	"'true'","'false'","'null'","'undefined'","'include'"
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
		default:return 0;
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
			while(loc<len&&isalpha(src[loc])||isdigit(src[loc])||src[loc]=='_')cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
			cur.type=getidtype(cur.val),toks.push_back(cur); 
		}
		else if(isdigit(src[loc])||src[loc]=='.'){
			bool d=0,e=0;
			if(src[loc]=='0'&&loc+1<len&&(src[loc+1]=='x'||src[loc+1]=='X')){
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				cur.val.push_back(src[loc]),(chkln,loc++,loc-1);
				while(loc<len&&isdigit(src[loc])||(src[loc]>='a'&&src[loc]<='f')||(src[loc]>='A'&&src[loc]<='F'))cur.val.push_back(tolower(src[loc])),(chkln,loc++,loc-1);
				cur.type=TOK_HEX,toks.push_back(cur);
			}
			else{
				while(loc<len&&isdigit(src[loc])||src[loc]=='.'||src[loc]=='E'||src[loc]=='e'||src[loc]=='-'){
					if(src[loc]=='.')if(!d)d=1;else break;
					if(src[loc]=='e'||src[loc]=='E')if(!e)e=1;else break;
					if(src[loc]=='-')if(loc-1>=0&&(src[loc-1]=='e'||src[loc-1]=='E'));else break;
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
	if(curtok==toks.size())fatal("expected token at the end of file",0);
	curtok++;
}
token readtok(char type){
	if(curtok>toks.size()||toks[curtok].type!=type)fatal("expected token %s at line %d, column %d",tokenname[type],toks[curtok].line,toks[curtok].column);
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
				default:fatal("unknown escaped char '\\%c'",x[i+1]);
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
		chklit(TOK_TRUE,"true",LOADTRUE);
		chklit(TOK_FALSE,"false",LOADFALSE);
		chklit(TOK_NULL,"null",LOADNULL);
		chklit(TOK_UNDEFINED,"undefined",LOADUNDEFINED);
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
			string f=anonyfunc();
			//s.push_back(LOADVAR);concat(s,loadint(getid(f)));
			readtok(TOK_FUNC);s.push_back(LOADFUNC);
			new_scope();
			readtok(TOK_LPR);b1=parse_params(tmp),readtok(TOK_RPR);
			concat(s,loadint(tmp));
			readtok(TOK_LBR);b2=compile_block(0);readtok(TOK_RBR);
			b2.push_back(LOADNULL),b2.push_back(RETURN);
			concat(s,loadint(b2.size()));
			concat(s,loadint(used_upvalues[used_upvalues.size()-1].size()));
			concat(s,b1),concat(s,compile_upvalue(f)),concat(s,b2);
			del_scope();
			//s.push_back(ASSIGN);
			break;
		}
		default:fatal("expected value at line %d, column %d",tok.line,tok.column);
	}
	#define PF(code) v=tok.val,pr=prior(tok.type);curtok++;concat(s,parse_expr(pr));s.push_back(code);break
	while(curtok<toks.size()&&prior(tok.type)>=precd){
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
			case TOK_OR:PF(OR);
			case TOK_AND:PF(AND);
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
		bool isref=0;
		if(tok.type==TOK_AND)readtok(TOK_AND),isref=1;
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
		else fatal("expected a property name at line %d, column %d (given: '%s')",tok.line,tok.column,tokenname[tok.type]);
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
	return s;
}
void fillholder(codeset&s,const uint&led){
	codeset b;
	for(int i=0;i+8<s.size();i++){
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
	b2.push_back(LOADNULL),b2.push_back(RETURN);
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
const char* valtypename[]={"number","string","null","function","Array","true","false","undefined"};
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
	val(int ref,valtype t){type=t,num=ref;}
	bool is_true()const{return !(type==TFALSE||type==TNULL||(type==TNUM&&num==0));}
	string tostr()const{
		switch(type){
			case TNUM:return num2str(num);
			case TSTR:return str;
			case TTRUE:case TFALSE:return type==TTRUE?"true":"false";
			case TREF:return "<ref "+num2str(num)+">";
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
		fatal("operation '+' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);
		return val(TFALSE);
	}
	#define math_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num;\
		fatal("operation '"#v"' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);\
		return val(TFALSE);\
	}
	math_method(-)
	math_method(*)
	math_method(/)
	val operator%(const val&b)const{
		if(type==TNUM&&b.type==TNUM)return fmod(num,b.num);
		fatal("operation '%' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);
		return val(TFALSE);
	}
	#undef math_method
	#define int_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return (ull)num v (ull)b.num;\
		fatal("operation '"#v"' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);\
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
		fatal("operation '<' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);
		return val(TFALSE);
	}
	#define bool_method(v)\
	val operator v (const val&b)const{\
		if(type==TNUM&&b.type==TNUM)return num v b.num?maketrue():makefalse();\
		fatal("operation '"#v"' can't be applied between '%s' and '%s'",valtypename[type],valtypename[b.type]);\
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
		fatal("unary operation '+' can't be applied on '%s'",valtypename[type]);
		return val(TFALSE);
	}
	val operator-()const{
		if(type==TNUM)return -num;
		fatal("unary operation '-' can't be applied on '%s'",valtypename[type]);
		return val(TFALSE);
	}
	val operator~()const{
		if(type==TNUM)return ~(ull)num;
		fatal("unary operation '~' can't be applied on '%s'",valtypename[type]);
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
const uint arrlength=1024*1024*2;
const uint objresv=arrlength/2;
vector<hashtable<int,val,hasher>>frames;
umap<string,uint>keyhash;
int usedhashslot;
uint getkeyhash(const string&s){if(keyhash.find(s)!=keyhash.end())return keyhash[s]=++usedhashslot+objresv;return keyhash[s];}
umap<int,umap<int,val,hasher>,hasher>upvalueframe;
umap<int,func,hasher>functable;
umap<int,val,hasher>heap;
umap<int,uint,hasher>arrlens;
vector<uint>regs;
vector<uint>funcstack; 
uint usedarrs;
uint usedfuncs;
int vmstack[RUNSTACK_SIZE];
typedef int* runstack;
inline void newframe(){frames.push_back(hashtable<int,val,hasher>()),regs.push_back(0);}
inline void delframe(){frames.pop_back(),regs.pop_back();}
inline val& generef(const int&addr,bool lcl=0){
	if(addr<0)return heap[addr];
	if(addr>=0&&!lcl){
		for(uint i=frames.size()-1;~i;i--)if(frames[i].has(addr))return frames[i][addr];
		if(upvalueframe[funcstack[funcstack.size()-1]].find(addr)!=upvalueframe[funcstack[funcstack.size()-1]].end())return upvalueframe[funcstack[funcstack.size()-1]][addr];
	}
	return frames[frames.size()-1][addr];
}
inline val& localref(int addr){return frames[frames.size()-1][addr]=val(TNULL),frames[frames.size()-1][addr];}
inline uint newreg(){return regs.size()*regoffset+(++regs[regs.size()-1]);}
inline void delreg(){regs[regs.size()-1]--;}
inline void freereg(const uint&addr){for(int i=frames.size()-1;~i;i--)if(frames[i].has(addr))frames[i].ctt.erase(addr);}
inline int allocarr(){return arrlength*(++usedarrs);}
inline uint getlen(val v){int addr;if(v.type==TSTR)return v.str.length();if(v.type==TREF)return addr=v.num,arrlens[(addr)/arrlength]+1;return 0;}
inline void mdfaddr(int addr){if(addr>=0)return;addr=-addr;arrlens[addr/arrlength]=max(arrlens[addr/arrlength],addr%arrlength);}
inline int getaddr(const val&addr,const val&offset){
	int r=0;
	if(addr.type==TSTR&&offset.type==TNUM){generef(r=newreg())=val(((string)"")+(addr.str[offset.num]));return r;}
	else if(addr.type==TREF&&offset.type==TNUM)return(-(addr.num+offset.num));
	else if(addr.type==TREF&&offset.type==TSTR)return(-(addr.num+getkeyhash(offset.str)));
	else fatal("operation '[]' can't be applied between '%s' and '%s'",valtypename[addr.type],valtypename[offset.type]);
	return r;
}
inline int newfunc(const vector<int>&pid,const codeset&instr,const vector<int>&upvs){
	usedfuncs++,functable[usedfuncs].pid=pid,functable[usedfuncs].instr=instr,functable[usedfuncs].upvs=upvs;
	for(auto a:upvs)upvalueframe[usedfuncs][a]=generef(a);
	return usedfuncs;
}
int call_func(const int&fid,const vector<int>&args,runstack stk_start);
int runbytes(const codeset&s,runstack stk_start){
	uint ip=0,len=s.size();
	runstack curstk,bottom;bottom=stk_start,curstk=stk_start;
	while(ip<len){
		switch(s[ip]){
			default:{
				fatal("unknown bytecode %02X at position %d",s[ip],ip);
				break;
			}
			case LOADSTR:{
				string str="";
				ip++;
				uint id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				uchar v=0;
				while(id--)v=s[++ip]*0xfu+s[++ip],str.push_back(v);
				*curstk=newreg();
				generef(*curstk)=val(str),curstk++;
				break;
			}
			case LOADTRUE:{
				int nr=newreg();generef(nr)=val(0,TTRUE),*curstk=nr,curstk++;
				break;
			}
			case LOADFALSE:{
				int nr=newreg();generef(nr)=val(0,TFALSE),*curstk=nr,curstk++;
				break;
			}
			case LOADNULL:{
				int nr=newreg();generef(nr)=val(0,TNULL),*curstk=nr,curstk++;
				break;
			}
			case LOADUNDEFINED:{
				int nr=newreg();generef(nr)=val(0,TUNDEF),*curstk=nr,curstk++;
				break;
			}
			case LOADVAR:case LOADVARLOCAL:{
				ip++;
				uint id=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				*curstk=id,curstk++;
				break;
			}
			case ASSIGN:case ASSIGNLOCAL:{
				generef(*(curstk-2),s[ip]==ASSIGNLOCAL)=generef(*(curstk-1)),mdfaddr(*(curstk-2));
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
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
				ip+=7;
				*curstk=newreg();
				generef(*curstk)=val(bpser.x),curstk++;
				break;
			}
			case POP:{
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;break;
				break;
			}
			#define MATH(v,sym)\
			case v:{\
				uint nr=newreg();\
				generef(nr)=generef(*(curstk-2)) sym generef(*(curstk-1));\
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));\
				curstk--,*(curstk-1)=nr;\
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
				uint nr=newreg();\
				generef(nr)=sym generef(*(curstk-1));\
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));\
				*(curstk-1)=nr;\
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
				int loc=allocarr(),nr=newreg();
				while(len--){
					generef(-(loc+len))=generef(*(curstk-1)),mdfaddr(-(loc+len));
					if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				generef(nr)=val(loc,TREF),*curstk=nr,curstk++;
				break;
			}
			case LOADOBJ:{
				ip++;
				int len=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				int loc=allocarr(),nr=newreg();
				val r=val(loc,TREF),key; 
				while(len--){
					key=generef(*(curstk-1));
					if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
					generef(getaddr(r,key))=generef(*(curstk-1)),mdfaddr(getaddr(r,key));
					if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
					curstk--;
				}
				generef(nr)=r,*curstk=nr,curstk++;
				break;
			}
			case GETADDR:{
				int nr=getaddr(generef(*(curstk-2)),generef(*(curstk-1)));
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--,*(curstk-1)=nr;
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
				int nr=newreg(),v;
				vector<int> pid,upvs;codeset instr;
				while(pcnt--)pid.push_back(s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(upvcnt--)upvs.push_back(v=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3]),ip+=4;
				while(size--)instr.push_back(s[ip]),ip++;
				ip--;
				int fid=newfunc(pid,instr,upvs);
				generef(nr)=val(fid,TFUNC);
				*curstk=nr,curstk++;
				break;
			}
			case CALL:{
				ip++;
				uint argscnt=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				vector<int> args,freelist;
				while(argscnt--){
					args.push_back(*(curstk-1));
					if(*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
					curstk--;
				}
				if(generef(*(curstk-1)).type!=TFUNC)fatal("can't call a non-function type '%s'(%s)",valtypename[generef(*(curstk-1)).type],generef(*(curstk-1)).tostr().c_str());
				
				int fid=generef(*(curstk-1)).num;
				if(*(curstk-1)>regoffset*regs.size())freelist.push_back(*(curstk-1));
				curstk--;
				int nr=call_func(fid,args,curstk);*curstk=nr,curstk++;
				for(auto a:freelist)freereg(a);
				break;
			}
			case RETURN:{
				int nr=newreg();
				generef(nr)=generef(*(curstk-1));
				return nr;
			}
			case JUMP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3+offset;
				break;
			}
			case JUMP_IF_FALSE:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip+=3;
				bool cond=generef(*(curstk-1)).is_true();
				if(*(curstk-1)>regoffset*regs.size())freereg(*(curstk-1));
				curstk--;
				if(!cond)ip+=offset;
				break;
			}
			case LOOP:{
				ip++;
				uint offset=s[ip]*0xffffff+s[ip+1]*0xffff+s[ip+2]*0xff+s[ip+3];
				ip-=1+offset;
				break;
			}
			case NEWFRAME:newframe();break;
			case DELFRAME:delframe();break;
		}
		ip++;
	}
}
set<int> builtin;

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
	inline void file_close(int handle){check_handle(handle);fclose(file_ptrs[handle]);}
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
};
inline int call_builtin(const int&fid,const vector<int>&args){
	#define param(x) (args[args.size()-1-(x)])
	val retv;
	#define arg(x) (generef(param(x)))
	#define valtype(x) (arg(x).type)
	#define chktype(x,t)\
	do{if(valtype(x)!=t)fatal("argument %d requires '%s' for %d, got '%s'\n",x,valtypename[x],fid,valtypename[valtype(x)]);}while(0)
	switch(fid){
		case 1:for(uint i=0;i<args.size();i++)cout<<arg(i).tostr()<<' ';cout<<endl;retv=args.size();break;
		case 2:chktype(0,TNUM);retv=arg(0);exit(arg(0).num);break;
		case 3:chktype(0,TNUM);retv=sin(arg(0).num);break;
		case 4:chktype(0,TNUM);retv=cos(arg(0).num);break;
		case 5:chktype(0,TNUM);retv=tan(arg(0).num);break;
		case 6:chktype(0,TNUM);retv=asin(arg(0).num);break;
		case 7:chktype(0,TNUM);retv=acos(arg(0).num);break;
		case 8:chktype(0,TNUM);retv=atan(arg(0).num);break;
		case 9:chktype(0,TNUM);chktype(1,TNUM);retv=atan2(arg(0).num,arg(1).num);break;
		case 10:chktype(0,TNUM);retv=exp(arg(0).num);break;
		case 11:chktype(0,TNUM);retv=log(arg(0).num);break;
		case 12:{
			chktype(0,TSTR);
			if(args.size()==1)retv=file_manager::file_open(arg(0).str);
			else{chktype(1,TSTR);retv=file_manager::file_open(arg(0).str,arg(1).str);}
			break;
		}
		case 13:chktype(0,TNUM);retv=file_manager::fread_number(arg(0).num);break;
		case 14:chktype(0,TNUM);retv=file_manager::fread_string(arg(0).num);break;
		case 15:chktype(0,TNUM);retv=file_manager::fread_line(arg(0).num);break;
		case 16:chktype(0,TNUM);for(uint i=1;i<args.size();i++)file_manager::fwrite_string(arg(0).num,arg(i).tostr());retv=args.size();break;
		case 17:retv=clock();break;
		case 18:chktype(0,TSTR);retv=system(arg(0).str.c_str());break;
		case 19:retv=rand();break;
		case 20:chktype(0,TNUM);srand(arg(0).num);retv=arg(0);break;
		case 21:retv=getlen(arg(0));break;
		default:exit(printf("Unknown builtin function id %d\n",fid)&&0);retv=0;break;
	}
	int nr=newreg();generef(nr)=retv;
	return nr;
}
inline int call_func(const int&fid,const vector<int>&args,runstack stk_start){
	if(builtin.find(fid)!=builtin.end())return call_builtin(fid,args);
	const vector<int> &pid=functable[fid].pid;
	if(functable[fid].pid.size()<args.size())fatal("function at %d needs at most %d argument(s), %d given",fid,functable[fid].pid.size(),args.size());
	vector<val>ag;ag.resize(args.size());
	for(int i=0;i<args.size();i++)ag[i]=generef(args[args.size()-1-i]);
	uint oldsize=frames.size();newframe();funcstack.push_back(fid);
	for(int i=0;i<ag.size();i++)generef(pid[i],1)=ag[i];
	int ret=runbytes(functable[fid].instr,stk_start);
	val v=generef(ret);
	while(oldsize<frames.size())delframe();funcstack.pop_back();
	int nr=newreg();
	return generef(nr)=v,nr;
}
bool inited;
void initvm(){
	if(inited)return;inited=1;
	memset(vmstack,0,sizeof(vmstack)); 
	newframe(),funcstack.push_back(-1);
	int r;
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("print"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("exit"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("sin"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("cos"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("tan"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("asin"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("acos"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("atan"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("atan2"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("exp"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("log"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("file_open"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("file_read_number"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("file_read_string"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("file_read_line"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("file_write"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("clock"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("system"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("rand"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("srand"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("len"))=val(r,TFUNC);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("math_pi"))=val(acos(-1));
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("credits"))=val(CREDITS);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("help"))=val(HELP);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("copyright"))=val(COPYRIGHT);
	r=newfunc(vector<int>(),codeset(),vector<int>()),builtin.insert(r),generef(getid("license"))=val(LICENSE);
	usedfuncs=1024;
	usedname=1024;
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
		new_scope(),vm::initvm();
		cout<<fixed<<setprecision(12)<<"RBQ 6.0\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information."<<endl;
		cout<<">>> ";
		while(getline(cin,str)){
		try{
			toks.clear(),curtok=0;
			for(uint i=0;i<str.size();i++)src[i]=str[i];src[str.size()]='\0';
			tokenize(src);codeset c;
			while(curtok<toks.size())concat(c,compile());
			if(c[c.size()-1]==POP)c[c.size()-1]=RETURN;
			cout<<vm::generef(vm::runbytes(c,vm::vmstack)).tostr()<<endl;
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
		if(!files.size())fatal("need at least one input source file to compile",0);
		for(auto a:files)read_source(a);
		start_compile2();return files[0];
	}
	void run_rbq(string arg){
		if(!arg.size())fatal("need a bytecode file to run",0);
		new_scope(),vm::initvm();codeset s;
		ifstream fcin(arg.c_str(),ios::binary);
		if(!fcin)fatal("can not open bytefile '%s'",arg.c_str()); 
		char c;while(fcin.get(c))s.push_back((uchar)c);
		vm::runbytes(s,vm::vmstack);
	}
}
signed main(signed argc,char **argv){
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
