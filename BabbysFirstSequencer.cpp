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

int main () {
	char input;
	/*Composition *song;
	song = new Composition("Untitled", 120);

	Sequence *first;
	first = new Sequence(16);
	song->sequences.push_back(*first);
	first->seqNum = 0;*/

	//song->printSequence(song, first);

	cout << "\n\n\t<1. Create Composition>";
	cout << "\n\tINPUT: ";
	cin >> input;

	switch (input) {
	case '1':
			break;
		default:
			break;
	}

	return 0;
}
