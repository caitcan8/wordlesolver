#include "solver.h"

void Solver::read(){
    wordlist.reserve(15000);
    ifstream file(filename);
    if(!file){
        cerr<<"Could not open "<<filename<<"\n";
    }
    string word;
    while(file>>word){
        wordlist.push_back(word);
    }
    cout<<"Green letters (use _ for unknowns): \n";
    //greenletters.reserve(5);
    string greens;
    getline(cin, greens);


    for(size_t i = 0; i < 5; ++i){
        char letter = greens[i];
        
        if(letter != '_'){
            //store green letters position and value 
            Green g = {letter, i};
            //cout<<g.letter;
            greenletters.push_back(g);
        }
    }
    cout<<"Yellow letters (use _ for non yellow spots): \n";
    //greenletters.reserve(5);
    string yellows;
    getline(cin, yellows);


    for(size_t i = 0; i < 5; ++i){
        char letter = yellows[i];
        
        if(letter != '_'){
            //store yellow letters incorrect position and value 
            Yellow y = {letter, i};
            //cout<<g.letter;
            yellowletters.push_back(y);
        }
    }

    cout<<"Gray letters (ex. abc):\n";
    string gray;
    getline(cin, gray);
    for(size_t i =0; i < gray.size(); ++i){
        //add gray letters 
        grayletters.push_back(gray[i]);
    }
}

void Solver::solve(){
    //bool found = false;
    bool bad = false;
    cout<<"Possible words: ";
    for(size_t i = 0; i < wordlist.size(); ++i){
        //first check green letters
        bad = false;
        string currword = wordlist[i];
        for(size_t j = 0; j < greenletters.size(); ++ j){
            if( greenletters[j].letter != currword[greenletters[j].pos])
            {
                bad = true;
                break;
            }
        }
        if(bad){
            continue;
        }
        //then check yellow
        bool yellowthere = false;
        bool included = false;
        for(size_t j =0; j < yellowletters.size(); ++j){
            included = false;
            //opposite condition 
            Yellow curr = yellowletters[j];
            if(curr.letter != '_'){
                yellowthere = true;
            }
            if( curr.letter == currword[curr.pos])
            {
                bad = true;
                break;
            }
            //check that it includes the yellow letters
            
            for(size_t k = 0; k < currword.size(); ++k){
                if(currword[k]==curr.letter){
                    included = true;
                    break;
                }
            }
        }
        
        if(bad){
            continue;
        }
        if(yellowthere && !included){
            continue;
        }
        

        //now check if any gray letters are included 
        for(size_t j = 0; j < grayletters.size(); ++j){
            for(size_t k = 0; k < currword.size(); ++k){
                if(currword[k]==grayletters[j]){
                    bad = true;
                    break;
                }
                
            }
            if(bad){
            continue;
             }
        }
        if(bad){
            continue;
        }
        //if it makes it here it passed all the constraints so print the word
        cout<<currword<<" ";
    }
}