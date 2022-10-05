#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	switch (where)
	{
	case -1:
		insert_front(playlist->list,song_id);
		break;
	
	case -2:
		insert_back(playlist->list,song_id);
		break;
	
	default:
		insert_after(playlist->list,song_id,where);
	}
	playlist->num_songs++;
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	if(is_empty(playlist->list))
		return;
	delete_node(playlist->list,song_id);
	playlist->num_songs--;	
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	return search(playlist->list,song_id);
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	playlist->last_song = search(playlist->list,song_id);
	if(playlist->last_song != NULL)
		play_song(song_id);
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if(!empty(q)) {
		play_from_queue(q);
	}
	else {
		if(is_empty(playlist->list))
			return;

		song_t *song = NULL;	
		if((playlist->last_song == NULL)||(playlist->last_song->next == NULL)) {
			song = playlist->list->head;
		}
		else {
			song = playlist->last_song->next;
		}
		play_song(song->data);
		playlist->last_song = song;
	}
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(is_empty(playlist->list))
			return;

	song_t *song = NULL;	
	if((playlist->last_song == NULL)||(playlist->last_song->prev == NULL)) {
		song = playlist->list->tail;
	}
	else {
		song = playlist->last_song->prev;
	}
	play_song(song->data);
	playlist->last_song = song;
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	if(!empty(q))
	{
		play_song(dequeue(q));
	}
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	if(is_empty(playlist->list) || playlist->num_songs == 1)
		return;

	song_t *current = playlist->list->head;
	song_t *prev = NULL;
	
	while(current != NULL) {
		prev = current->prev;
		current->prev = current->next;
		current->next = prev;
		current = current->prev;
	}
	current = playlist->list->head;
	playlist->list->head = playlist->list->tail;
	playlist->list->tail = current;
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	int j = 0;
	node_t* nodeNumK = playlist->list->head;

	while(nodeNumK != NULL && j < k) 
	{
		nodeNumK = nodeNumK->next;
		j++;
	}

	if(nodeNumK != NULL) 
	{
		node_t* NodeNumI = playlist->list->head;
		int i = 0;

		node_t* nodeNumKNext = NULL; 
		node_t* nodeNumKPrev = NULL;
		node_t* nodeNumNextI = NULL;
		node_t* nodeNumPrevI = NULL;

		while(i + k < playlist->list->size) 
		{
			nodeNumNextI = NodeNumI->next;
			nodeNumPrevI = NodeNumI->prev;
			nodeNumKNext = nodeNumK->next;
			nodeNumKPrev = nodeNumK->prev;

			if(NodeNumI->next == nodeNumK) 
			{
				NodeNumI->prev = nodeNumK;
				nodeNumK->next = NodeNumI;
				nodeNumK->prev = nodeNumPrevI;
				NodeNumI->next = nodeNumKNext;
				
				if(nodeNumKNext != NULL) 
				{
					nodeNumKNext->prev = NodeNumI;
				}

				else 
				{
					playlist->list->tail = NodeNumI;
				}

				if(nodeNumPrevI != NULL) 
				{
					nodeNumPrevI->next = nodeNumK;
				}

				else 
				{
					playlist->list->head = nodeNumK;
				}
				
				nodeNumK = nodeNumKNext;
				
			}

			else 
			{
				NodeNumI->prev = nodeNumKPrev;
				nodeNumK->next = nodeNumNextI;
				nodeNumK->prev = nodeNumPrevI;
				NodeNumI->next = nodeNumKNext;
				
				nodeNumNextI->prev = nodeNumK;
				nodeNumKPrev->next = NodeNumI;

				if(nodeNumKNext != NULL) 
				{
					nodeNumKNext->prev = NodeNumI;
				}

				else 
				{
					playlist->list->tail = NodeNumI;
				}

				if(nodeNumPrevI != NULL) 
				{
					nodeNumPrevI->next = nodeNumK;
				}

				else 
				{
					playlist->list->head = nodeNumK;
				}

				NodeNumI = nodeNumNextI;
				nodeNumK = nodeNumKNext;
			}

			i++;
		}
	}
}
void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist,k);
	reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	song_t *tempNode = playlist->list->head;
	while (tempNode != NULL)
	{
		if(tempNode == playlist->list->tail->next)
			return tempNode;
		tempNode = tempNode->next;	
	}
	return NULL;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}
