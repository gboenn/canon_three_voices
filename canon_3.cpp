#include <iostream>
#include <random>
#include "Modul.h"

void make_cadence_0 (int last_pivot, vector<int>& notes, string& lead, string& second, string& third) {
    
    cout << lead << endl << second << endl << third << endl;
    // in option 0 (I.) comes1 one is four steps below dux (5th)
    int comes1_pivot = last_pivot - 4;
    // in option 0 (I.) comes2 one is 4 steps above dux (4th)
    int comes2_pivot = last_pivot + 3;
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    last_pivot -= 2;
    int apu = notes[last_pivot];
    if ((apu+1) % 12 == 0){
        // if the downstep by a third lands on b then make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    last_pivot += 1;
    apu = notes[last_pivot];
    if ((apu+1) % 12 == 0) {
        // if the second note is a b make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    last_pivot += 2;
    apu = notes[last_pivot];
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    apu -= 1;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    apu += 1;
    int finalis = apu;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // comes1 cadence:
    // comes 1 ends in an ocatve with dux and must do a major second up and down movt
    // ex. ending on b: b c# b
    // musica ficta problem
    comes1_pivot -= 2;
    apu = notes[comes1_pivot];
    second += std::to_string(apu);
    second += ",";
    comes1_pivot += 1;
    int apu1 = notes[comes1_pivot];
    if ((apu1 - apu) == 1) {
        apu1++;
    }
    second += std::to_string(apu1);
    second += ",";
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    second += std::to_string(apu);

    // comes2 cadence
    // comes 2 ends on the third (major) but starts with minor third
    // ex. ending in e: g a g#
    // but if the first note is already the major third
    // then the second note needs to be a half step up
    // ex. a b-flat a
    apu = notes[comes2_pivot];
    cout << "comes2 pivot note: " << apu << endl;
    if ((begin_cad + 5 +2) % 12 == 0) {
//        if there is a b flat in comes 2 at the beginning
//        apu is already a b natural with this expr: apu = notes[comes2_pivot];
//        because we use the gammut instead of literal transpoition of the interval
        cout << "(begin_cad + 5 +2) % 12 == 0: " << apu << endl;
        apu += 1;
        third += std::to_string(apu);
        third += ",";
        apu -= 1;
        third += std::to_string(apu);
    }
    else if (abs(finalis - apu) == 4) {
        // if major third is distance to the dux during cadence
        comes2_pivot += 1;
        if (abs(apu - notes[comes2_pivot]) == 2) {
            cout << apu << " " << notes[comes2_pivot] << endl;
            apu = notes[comes2_pivot] - 1; // this has to be a half step only
            
        } else {
            apu = notes[comes2_pivot];
        }
        third += std::to_string(apu);
        third += ",";
        comes2_pivot -= 1;
        apu1 = notes[comes2_pivot];
        third += std::to_string(apu1);
    } else {
        apu += 2;
        third += std::to_string(apu);
        third += ",";
        apu -= 1;
        third += std::to_string(apu);
        // end with the picardi third
    }
}

void make_cadence_1 (int last_pivot, vector<int>& notes, string& lead, string& second, string& third) {
    // three thirds in a row create octave parallels during cadence
    // therefore, don't start this cadence after dux had a descending third.
    cout << lead << endl << second << endl << third << endl;
    // in option 1 (II.) comes1 one is one octave above dux (5th)
    int comes1_pivot = last_pivot + 7;
    // in option 1 (II.) comes2 one is 4 steps above dux (4th)
//    int comes2_pivot = last_pivot + 3;
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    last_pivot -= 2; // lower a third
    int apu = notes[last_pivot];
    if ((apu+1) % 12 == 0){
        // if the downstep by a third lands on b then make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 2; // lower another third
    int apu1 = notes[last_pivot];
    if ((apu1+1) % 12 == 0){
        // if the downstep by a third lands on b then make it b flat
        apu1--;
    }
    canti.push_back(apu1);
    lead += std::to_string(apu1);
    lead += ",";
    
    // go back up a third
    last_pivot += 2;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1; // lower a step
    apu1 = notes[last_pivot];
    if((apu1-5)%12==0) {
        // if penultima f then raise to f#
        apu1++;
    }
    canti.push_back(apu1);
    lead += std::to_string(apu1);
    lead += ",";
    
    // go back up a step
    last_pivot += 1;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    int finalis = apu;
    
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // comes1 cadence:
    
    // lower a third
    comes1_pivot -= 2;
    apu = notes[comes1_pivot];
    if ((apu+1) % 12 == 0){
        // if the downstep by a third lands on b then make it b flat
        apu--;
    }
    second += std::to_string(apu);
    second += ",";
    
    // from where we are
    apu = notes[comes1_pivot];
    // up a step
    comes1_pivot += 1;
    apu1 = notes[comes1_pivot];
    if ((apu1+1) % 12 == 0){
        // if it lands on b then make it b flat
        apu1--;
    }
    second += std::to_string(apu1);
    second += ",";
    
    //DOWN A STEP
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    if ((apu+1) % 12 == 0){
        // if it lands on b then make it b flat
        apu--;
    }
    second += std::to_string(apu);
       second += ",";
    
    // comes2 cadence
    // comes 2 ends on the picardian third (major)

    apu = finalis + 5;
    third += std::to_string(apu);
    third += ",";
    apu = finalis + 4;
    third += std::to_string(apu);
    third += ",";
    
}

void make_cadence_2 (int last_pivot, vector<int>& notes, string& lead, string& second, string& third) {
    //option two musica ficta problem in cadence? f# b not f bb
    cout << lead << endl << second << endl << third << endl;
    // in option 2 (III.) comes1 one is one fifth - 4 steps - above dux (5th)
    int comes1_pivot = last_pivot + 4;
    // in option 2 (III.) comes2 one is 3 steps below dux (4th)
    int comes2_pivot = last_pivot - 3;
    // the cadence end in an octave/unison interval
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    last_pivot += 2; // rise a third
    int apu = notes[last_pivot];
    if ((apu-5) % 12 == 0){
        // if the movement by a third lands on f then make it f#
        apu++;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1; //  lower a step
    int apu1 = notes[last_pivot];
    if ((apu1-5) % 12 == 0){
        // if the downstep lands on f then make it f#
        apu1++;
    }
    canti.push_back(apu1);
    lead += std::to_string(apu1);
    lead += ",";
    
    // go back up a fourth
    last_pivot += 3;
    apu = notes[last_pivot];
//    if ((apu+1) % 12 == 0){
//        // if the movement by a third lands on b then make it b flat
//        apu--;
//    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1; // lower a step
    --apu; // leading tone half step
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    // go back up a step
    last_pivot += 1;
    ++apu; // leading tone half step
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    int finalis = apu;
    
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // comes1 cadence:
    
    // up a third
    comes1_pivot += 2;
    apu = notes[comes1_pivot];
    if ((apu+1) % 12 == 0){
        // if the step by a third lands on b then make it b flat
        apu--;
    }
    second += std::to_string(apu);
    second += ",";
    
    // down a step
    comes1_pivot -= 1;
    apu1 = notes[comes1_pivot];
    if ((apu1) % 12 == 0){
        // if it lands on c then make it c#
        apu1++;
    }
    if ((apu1-5) % 12 == 0){
        // if it lands on f then make it f#
        apu1++;
    }
    second += std::to_string(apu1);
    second += ",";
    
    //DOWN A STEP
    comes1_pivot -= 1;
    apu = notes[comes1_pivot];
    second += std::to_string(apu);
       second += ",";
    
    // comes2 cadence
    // comes 2 ends on the picardian third (major)
    
    // test last note of third voice so far:
    int ln = stoi(third.substr(third.length() - 3, 2)); // 3 because of last char == ','
    // and double digit midi notes
    // cout << "test last note of third voice so far: " << ln << endl;
    if ((ln - 6) % 12 == 0) {
        // if this note is an f#, lower to f
        --ln;
        third.replace((third.length() - 3), 2, to_string(ln));
        cout << third << endl;
    }
    comes2_pivot -= 3;
    apu = notes[comes2_pivot];
    if ((apu-5) % 12 == 0 && (finalis+1)%12==0 ){
        // if the movement by a fourth gives f, taise to f#, but only if finalis is b
        apu++;
    }
    third += std::to_string(apu);
    third += ",";
    comes2_pivot += 3;
    apu = notes[comes2_pivot];
    third += std::to_string(apu);
    third += ",";
    
}

void make_cadence_3 (int last_pivot, vector<int>& notes, string& lead, string& second, string& third) {
    
    cout << lead << endl << second << endl << third << endl;
    // in option 3 (IV.) comes1 one is one octave - 7 steps - below dux (8ve)
    int comes1_pivot = last_pivot - 7;
    // in option 3 (IV.) comes2 one is one fourth - 3 steps - below dux (4th)
    int comes2_pivot = last_pivot - 3;
    // the cadence end in an octave/unison interval
    
    // do the cantizans cadence:
    vector<int> canti;
    int begin_cad = notes[last_pivot];
    cout << "begin_cad: " << begin_cad << endl;
    last_pivot += 2; // rise a third
    int apu = notes[last_pivot];
    if ((apu+1) % 12 == 0){
        // if the movement by a third lands on b then make it b flat
        apu--;
    }
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 3; //  lower a fourth
    int apu1 = notes[last_pivot];
    canti.push_back(apu1);
    lead += std::to_string(apu1);
    lead += ",";
    
    // go back up a fourth
    last_pivot += 3;
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    last_pivot -= 1; // lower a step
    --apu; // leading tone half step
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    
    // go back up a step
    last_pivot += 1;
    ++apu; // leading tone half step
    canti.push_back(apu);
    lead += std::to_string(apu);
    lead += ",";
    int finalis = apu;
    
    for (auto it = canti.begin(); it != canti.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // comes1 cadence:
    
    // up a third
    comes1_pivot += 2;
    apu = notes[comes1_pivot];
    if ((apu+1) % 12 == 0){
        // if the step by a third lands on b then make it b flat
        apu--;
    }
    second += std::to_string(apu);
    second += ",";
    
    // from where we are
    // down a fourth
    comes1_pivot -= 3;
    apu1 = notes[comes1_pivot];
    if ((apu1-5) % 12 == 0 && (finalis+2)%12!=0 ){
        // if it lands on f then make it f#
        // but not if it ends in Bb
        apu1++;
    }
    second += std::to_string(apu1);
    second += ",";
    
    //DOWN A STEP
    comes1_pivot += 3;
    apu = notes[comes1_pivot];
    if ((apu+1) % 12 == 0){
        // if it lands on b then make it b flat
        apu--;
    }
    second += std::to_string(apu);
       second += ",";
    
    // comes2 cadence
    // comes 2 ends on the picardian third (major)
    
    comes2_pivot -= 1;
    apu = notes[comes2_pivot];
    if ((apu-5)%12==0)
//        if penultima lands on f make f#
        ++apu;
    third += std::to_string(apu);
    third += ",";
    comes2_pivot -= 1;
    apu = notes[comes2_pivot];
    if ((finalis+2)%12==0)
        // if dux finishes in Bb
        apu--;
    third += std::to_string(apu);
    third += ",";
    
}

int main (int argc, char *argv[]) {
    string usage = "Usage: sketch <0,1,2, or 3> <optional: number of notes >=1 >\n";
    if (argc < 2) {
        cout << usage << endl;
        return 0;
    }
        
    string a = "";
    int option = -1;
    unsigned long num_notes = 12; // the number of notes
    // this can be set by the command line
    
   for(int ndx{}; ndx != argc; ++ndx) {
        a = argv[ndx];
        if (ndx == 1)
            option = stoi(a);
        if (ndx == 2)
            num_notes = stoul(a);
    }
    
    if (option < 0 || option > 3) {
        cout << usage << endl;
        return 0;
    }
    
    if (num_notes < 1) {
        cout << usage << endl;
        return 0;
    }

    Modul m;
    random_device rd;
    mt19937 md(rd());
    vector<int> scale = {2,2,1,2,2,2,1};
    vector<int> notes;
    int note = 24;
    notes.push_back (note);
    for (auto i = 0; i < 5; i++) {
        for (auto it = scale.begin(); it != scale.end(); ++it) {
            note += *it;
            notes.push_back (note);
        }
    }
    
    // in three-voice canons no step-wise motion
    // except for embellishments, passing notes etc.
    cout << "at the fifth below" << endl;
    vector<int> intervals_5b = {3,0,-2,-4};
    if (option == 2 || option == 3) {
        cout << "at the fifth above" << endl;
        intervals_5b = {2,4,0,-3};
    }
    uniform_real_distribution<double> dist_up(0, intervals_5b.size());
    
    int pivot = 19;
    if (option == 0 || option == 2) {
        pivot = 19; // A3
    }
    if (option == 1) {
        pivot = 15; // D3
    }
    if (option == 3) {
        pivot = 22; // D4
    }
    vector<int> dux;
    dux.push_back(notes[pivot]);
    int prev_note = notes[pivot];
    int curr_note = notes[pivot];
    int prev_intv = 0;
    int prpr_intv = 0; // previous previous interval
    int curr_intv = 0;
    while (dux.size() < num_notes) {
        //pick at random from the list of possible intervals
        unsigned long r = static_cast<unsigned long>(dist_up(md));
        curr_intv = intervals_5b[r];
        // no repetition after ascending fourth
        // in order to prevent parallel movement between the dux and the 3rd voice
        if (curr_intv == 0 && prev_intv == 3)
            continue;
        //avoid -3 0 -3 or 3 0 3 which creates parallels
        if (abs(curr_intv) == 3 && prev_intv == 0 && abs(prpr_intv) == 3)
            continue;
        // avoid a big interval after a small one in the same direction
        int check = abs(curr_intv + prev_intv);
        // avoid more than one note repitition
        int check2 = abs(curr_intv) + abs(prev_intv);
//        avoid two thirds in a row and jumping fourth and fifth in a row
        cout << check << " (<4,!0) " << check2 << " (!6 !7 )" << endl;
        if (check < 4 && check != 0 && check2 != 6  && check2 != 7) {
            cout << check << " (<4,!0) " << check2 << " (!6 !7 )" << endl;
            // range checking (notes)
            if (pivot + curr_intv < 0)
                continue;
            if (static_cast<unsigned long>(pivot + curr_intv) >= notes.size())
                continue;
            
            pivot += curr_intv;
            curr_note = notes[pivot];
            // no repeat on b
            if (option == 2) {
                if (((curr_note+1)%12==0) && ((prev_note+1)%12==0)) {
                    cout << "two b in sequence" << endl;
                    // go up a third
                    curr_intv = 2;
                    pivot += curr_intv;
                    curr_note = notes[pivot];
//                    continue;
                }
            }
                
            // no tritone jump
            if (abs(curr_note - prev_note) != 6
                && abs(curr_note - prev_note) < 9) {
                if (option == 3) {
                    // if very last note before the cadence
                    // is a g (d) and before was an e (b)
                    // then repeat e (b) instead (avoid diminished chord in line
                    // and chromatic dissonant clashes with the 2 comes)
                    if (dux.size() == num_notes-1){
                        if ((curr_note+5)%12==0 && (prev_note-4)%12==0) {
                            pivot -= curr_intv;
                            curr_intv = prev_intv;
                        } else if ((curr_note-2)%12==0 && (prev_note+1)%12==0) {
                            pivot -= curr_intv;
                            curr_intv = prev_intv;
                        }
                    }
                }
                dux.push_back(notes[pivot]);
                prev_note = curr_note;
                prpr_intv = prev_intv;
                prev_intv = curr_intv;
                
            } else {
                // reset pivot
                pivot -= curr_intv;
            }
        }
    }
    
    string midiline = "";
    ofstream rhy("rhythm.txt");
    ofstream output("mel.txt");
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        midiline += std::to_string(*it) + ", ";
    }
    
    string comes = "";
    string comes2 = "";
    if (option == 0) {
        comes = m.Transpose2(midiline, -7.);
        comes2 = m.Transpose2(midiline, 5.);
        make_cadence_0 (pivot, notes, midiline, comes, comes2);
    }
    if (option == 1) {
        comes = m.Transpose2(midiline, 12.);
        comes2 = m.Transpose2(midiline, 5.);
        make_cadence_1 (pivot, notes, midiline, comes, comes2);
    }
    if (option == 2) {
        comes = m.Transpose2(midiline, 7.);
        comes2 = m.Transpose2(midiline, -5.);
        make_cadence_2 (pivot, notes, midiline, comes, comes2);
    }
    if (option == 3) {
        comes = m.Transpose2(midiline, -12.);
        comes2 = m.Transpose2(midiline, -5.);
        make_cadence_3 (pivot, notes, midiline, comes, comes2);
    }
    
    output  << midiline << endl;
    cout << "dux: " << midiline << endl;
    
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        rhy << "W";
    }
    if (option == 0)
        rhy << "WHWHW";
    else if (option == 1)
        rhy << "WHWHW";
    else if (option == 2)
        rhy << "WHWHW";
    else if (option == 3)
        rhy << "WHWHW";
    rhy << endl;
    
    output << "S" << endl;
    output  << comes << endl;
    cout << "comes1: " << comes << endl;
    rhy << "S" << endl << "(W)";
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        rhy << "W";
    }
    if (option == 0)
        rhy << "WWW";
    else if (option == 1)
        rhy << "WWW";
    else if (option == 2)
        rhy << "WWW";
    else if (option == 3)
        rhy << "WWW";
    rhy << endl;
    output << "S" << endl;
    output  << comes2 << endl;
    cout << "comes2: " << comes2 << endl;
    rhy << "S" << endl << "(WW)";
    for (auto it = dux.begin(); it != dux.end(); ++it) {
        rhy << "W";
    }
    if (option == 0)
        rhy << "WW";
    else if (option == 1)
        rhy << "WW";
    else if (option == 2)
        rhy << "WW";
    else if (option == 3)
        rhy << "WW";
    rhy << endl;
    output.close();
    rhy.close();
    m.Translate_Shorthand("rhythm.txt", "mel.txt", 8);
//    system("lilypond.sh transcription.ly");
//    system("preview.sh transcription.pdf");
//    system("timidity -T 180 transcription.midi");
  return 0;
}

