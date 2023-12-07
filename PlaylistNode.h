#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
public:
    // Constructors
    PlaylistNode();
    PlaylistNode(const string& uniqueID, const string& songName, const string& artistName, int songLength);

    // Accessors
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    // Mutators
    void SetNext(PlaylistNode* nodePtr);
    void InsertAfter(PlaylistNode* nodePtr);

    // Other
    void PrintPlaylistNode() const;

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif  
