/* @JUDGE_ID: 19899RK 464 C++ "By Anadan" */ 
// Sentence/Phrase Generator
// Accepted (0.207 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

void sentence(); void transsentence(); void intranssentence(); void subject();
void object(); void nounphrase(); void modifiednoun(); void modifier();
void verbphrase(); void intransverbphrase(); void prepphrase(); void noun();
void transverb(); void intransverb(); void article(); void adjective();
void adverb(); void preposition();

int choice, out;

const char names[][20] = {
	"sentence", "trans-sentence", "intrans-sentence", "subject", "object",
	"noun-phrase", "modified-noun", "modifier", "verb-phrase",
	"intrans-verb-phrase", "prep-phrase", "noun", "trans-verb",
	"intrans-verb", "article", "adjective", "adverb", "preposition", "empty"
};

inline int getchoice(int limit) { return choice++ % limit; }

inline void outprint(const char *s){
	if (out) putchar(' '); else out = 1;
	printf("%s", s);
}

const char prepositions[3][10] = { "on", "over", "through" };
void preposition() { outprint(prepositions[getchoice(3)]); }

const char adverbs[3][11] = { "nearly", "suddenly", "restlessly" };
void adverb() { outprint(adverbs[getchoice(3)]); }

const char adjectives[4][10] = { "green", "small", "rabid", "quick" };
void adjective() { outprint(adjectives[getchoice(4)]); }

void article() { outprint(getchoice(2) ? "a" : "the"); }

const char intransverbs[4][10] = { "slept", "jumped", "walked", "swam" };
void intransverb() { outprint(intransverbs[getchoice(4)]); }

const char transverbs[4][10] = { "struck", "saw", "bit", "took" };
void transverb() { outprint(transverbs[getchoice(4)]); }

const char nouns[5][10] = { "man", "dog", "fish", "computer", "waves" };
void noun() { outprint(nouns[getchoice(5)]); }

void prepphrase(){
	if (!getchoice(2)) { preposition(); nounphrase(); }
}

void intransverbphrase(){
	if (getchoice(2)) adverb();
	intransverb();
}

void verbphrase(){
	if (getchoice(2)) adverb();
	transverb();
}

void modifier(){
	if (getchoice(2)) adverb();
	adjective();
}

void modifiednoun(){
	if (getchoice(2)) modifier();
	noun();
}

void empty() {}
void nounphrase() { article(); modifiednoun(); }
void object()  { nounphrase(); }
void subject() { nounphrase(); }
void intranssentence() { subject(); intransverbphrase(); prepphrase(); }
void transsentence() { subject(); verbphrase(); object(); prepphrase(); }

void sentence(){
	if (getchoice(2)) intranssentence();
	else transsentence();
}

int main(){
	int i;
	char str[20];

	typedef void (*void_func)();
	void_func funcs[] = { sentence, transsentence, intranssentence,
		subject, object, nounphrase, modifiednoun, modifier, verbphrase,
		intransverbphrase, prepphrase, noun, transverb, intransverb,
		article, adjective, adverb, preposition, empty };

	choice = 1;
	while (scanf("%s\n", str) == 1){
		out = 0;
		for (i = 0; strcmp(names[i], str); ++i);
		funcs[i]();
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
