#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Track {
	char root;
	vector<char> notes;

	Track (char r) {
		root = r;
	}
};

struct Sequence{
	int length;
	int seqNum;
	Track *track;
	vector<Track*> tracks;
	Sequence *next;
	Sequence *previous;

	Sequence (int l) {
		length = l;
		next = NULL;
		previous = NULL;
	}
};

struct Composition {
	string title;
	int tempo;
	vector<Sequence> sequences;

	Composition (string ti, int te) {
		title = ti;
		tempo = te;
	}

	void printSequence(Composition* &comp, Sequence* &seq) {
		cout << "============================ C O M P O S I T I O N\n";
		cout << "\tTitle: " << comp->title << " \tTempo: " << comp->tempo << " BPM\n";
		if (comp->sequences.empty() == true) {
			cout << "<no sequences>\n\n";
		}
		else {
			cout << "============================ Sequence " << seq->seqNum << "\n\n";
			if (seq->tracks.empty() == true) {
				cout << "<no tracks>\n\n";
			}
			else {
				for (auto track : seq->tracks) {
					cout << "\t\t" << track->root << "||";
					for (auto note : track->notes) {
						cout << " " << note;
					}
					cout << "\n\n";
				}
			} 
	}
	}
};

void addSequence(Composition* &comp, Sequence* &prev, int l) {
	prev->next = new Sequence(l);
	prev->next->previous = prev;
	prev->next->seqNum += prev->seqNum;
	comp->sequences.push_back(*prev->next); 

}

void addTrack(Sequence* &seq, char r) {
	seq->track = new Track(r);
	for (int i = 0; i < seq->length; i++) {
		seq->track->notes.push_back('-');
	}
	seq->tracks.push_back(seq->track);
}

Composition addComposition () {
	string userTitle;
	int userTempo;
	
	cout << "\n\n\tEnter Title: ";
	cin >> userTitle;
	cout << "\n\tEnter Tempo: ";
	cin >> userTempo;

	return Composition(userTitle, userTempo);
}

int main () {
	char input;
	Composition *comp;
	/*Composition *song;
	song = new Composition("Untitled", 120);

	Sequence *first;
	first = new Sequence(16);
	song->sequences.push_back(*first);
	first->seqNum = 0;*/

	//song->printSequence(song, first);

inputCatch:
	cout << "\n\n\t<1. Create Composition>";
	cout << "\n\t<2. QUIT>";
	cout << "\n\tINPUT: ";
	cin >> input;

	switch (input) {
		case '1':
			comp = new Composition(addComposition());
			cout << string(50, '\n');
			break;
		case '2':
			cout << "\n\n\tSee ya~\n\n";
			return 0;
			break;
		default:
			goto inputCatch;
			break;
	}

	Sequence *first;
	first = new Sequence(16);
	comp->sequences.push_back(*first);
	first->seqNum = 0;

	comp->printSequence(comp, first);

	return 0;
}
