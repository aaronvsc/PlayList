// GITHUB REPOSITORY LINK: https://github.com/aaronvsc/PlayList.git
// I worked on this lab alone - Aaron Santa Cruz

#include <iostream>
#include "PlaylistNode.h"

using namespace std;


void PrintMenu(const string& playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

PlaylistNode* ExecuteMenu(char choice, const string& playlistTitle, PlaylistNode* head) {
    switch (choice) {
        case 'a': {
            // Add song
            cout << "ADD SONG" << endl;

            // Placeholder logic to get input for a new song
            string uniqueID, songName, artistName;
            int songLength;

            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);

            cout << "Enter song's name:" << endl;
            getline(cin, songName);

            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cout << endl;
            cin >> songLength;
            cin.ignore(); // Ignore newline character in the input buffer

            // Placeholder logic to create and add a new PlaylistNode to the linked list
            PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
            if (head == nullptr) {
                head = newNode;
            } else {
                PlaylistNode* current = head;
                while (current->GetNext() != nullptr) {
                    current = current->GetNext();
                }
                current->InsertAfter(newNode);
            }

            break;
        }

        case 'd': {
            // Remove song
            cout << "REMOVE SONG" << endl;

            // Placeholder logic to get input for the unique ID of the song to be removed
            string uniqueID;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);

            // Placeholder logic to find and remove the specified song from the linked list
            PlaylistNode* current = head;
            PlaylistNode* previous = nullptr;

            while (current != nullptr && current->GetID() != uniqueID) {
                previous = current;
                current = current->GetNext();
            }

            if (current == nullptr) {
                cout << "Song with ID \"" << uniqueID << "\" not found." << endl;
            } else {
                if (previous != nullptr) {
                    previous->SetNext(current->GetNext());
                } else {
                    head = current->GetNext();
                }

                cout << "\"" << current->GetSongName() << "\" removed." << endl;
                cout << endl;
                delete current; // Free memory of the removed node
            }

            break;
        }
         
         // Skip step 9 (case 'c')

        case 's': {
            // Output songs by specific artist
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;

            // Placeholder logic to get input for the artist's name
            string artistName;
            cout << "Enter artist's name:" << endl;
            cout << endl;
            getline(cin, artistName);

            if (head == nullptr) {
                cout << "Playlist is empty" << endl;
            } else {
                int position = 1;
                PlaylistNode* current = head;

                while (current != nullptr) {
                    if (current->GetArtistName() == artistName) {
                        cout << position << "." << endl;
                        current->PrintPlaylistNode();
                        cout << endl;
                    }

                    current = current->GetNext();
                    position++;
                }

                if (position == 1) {
                    // No songs found for the specified artist
                    cout << "No songs found for artist \"" << artistName << "\"" << endl;
                }
            }

            break;
        }

        case 't': {
            // Output total time of playlist
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

            int totalTime = 0;
            PlaylistNode* current = head;

            while (current != nullptr) {
                totalTime += current->GetSongLength();
                current = current->GetNext();
            }

            cout << "Total time: " << totalTime << " seconds" << endl;
            cout << endl;
            break;
        }

        case 'o': {
            // Output full playlist
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

            if (head == nullptr) {
                cout << "Playlist is empty" << endl;
                cout << endl;
            } else {
                int position = 1;
                PlaylistNode* current = head;

                while (current != nullptr) {
                    cout << position << "." << endl;
                    current->PrintPlaylistNode();
                    cout << endl;

                    current = current->GetNext();
                    position++;
                }
            }

            break;
        }

        case 'q':
            // Quit
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
    }

    return head;
}


int main() {
    string playlistTitle;

    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playlistTitle);

    PlaylistNode* head = nullptr; // Initialize head of the linked list

    char choice;
    do {
        PrintMenu(playlistTitle);
        cout << "Choose an option:" << endl;
        cin >> choice;
        cin.ignore(); // Ignore newline character in the input buffer

        head = ExecuteMenu(choice, playlistTitle, head);
    } while (choice != 'q');

    // Clean up memory (free allocated nodes)
    PlaylistNode* current = head;
    while (current != nullptr) {
        PlaylistNode* temp = current;
        current = current->GetNext();
        delete temp;
    }

    return 0;
}


