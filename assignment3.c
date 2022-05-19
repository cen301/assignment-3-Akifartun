//  Program:    Labeled Facebook Posts
//  Purpose:    every post should be categorized according to the post of the features.
//  Author:     Akif Artun
//  Date:       19/05/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float calculate_euclidean_distance(int reactions, int comments, int shares, int likes, int loves, int wows, int hahas, int sads, int angrys);
//  Calculates euclidean distance with formula
//  Parameters:     reactions, comments, shares, likes, loves, wows, hahas, sads, angrys (from the given dataset)
//  Return:         calculated ecludiean distance (float)

int main() {

    char id[10], type[10], reactions[10], comments[10], shares[10], likes[10], loves[10], wows[10], hahas[10], sads[10], angrys[10], category[30];
    int status_id, status_type, num_reactions, num_comments, num_shares, num_likes, num_loves, num_wows, num_hahas, num_sads, num_angrys;

    FILE *fpt1, *fpt2;
    fpt1 = fopen("facebook_post_dataset.txt","r");
    fpt2 = fopen("updated_facebook_post_database.txt","w");

    if(fpt1 == NULL) {
        printf("The file could not opened.");
        exit(1);
    }

    char lines[200];

    while(fgets(lines,sizeof(lines),fpt1) ){
            
        sscanf(lines, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^',']", id, type, reactions, comments, shares, likes, loves, wows, hahas, sads, angrys);
        status_id  = atoi(id);
        num_reactions  = atoi(reactions);
        num_comments  = atoi(comments);
        num_shares  = atoi(shares);
        num_likes  = atoi(likes);
        num_loves  = atoi(loves);
        num_wows  = atoi(wows);
        num_hahas  = atoi(hahas);
        num_sads  = atoi(sads);
        num_angrys  = atoi(angrys);

        int distance = calculate_euclidean_distance(num_reactions,num_comments,num_shares,num_likes,num_loves,num_wows,num_hahas,num_sads,num_angrys);

        if(distance > 592) {
            if((strcmp(type,"video") == 0) || (strcmp(type,"photo") == 0)) {
                strcpy(category,"very interesting");
            } if((strcmp(type,"link") == 0) || (strcmp(type,"status") == 0)) {
                strcpy(category,"interesting");
            }
        } else {
            if((strcmp(type,"video") == 0) || (strcmp(type,"photo") == 0)) {
                strcpy(category,"ordinary");
            } if((strcmp(type,"link") == 0) || (strcmp(type,"status") == 0)) {
                strcpy(category,"boring");
            }
        }
        
        fprintf(fpt2,"%s %s\n", lines, category);

        
    }

    

}

float calculate_euclidean_distance(int reactions, int comments, int shares, int likes, int loves, int wows, int hahas, int sads, int angrys){
    
    float calculated = sqrt(pow((reactions - 230.12),2) + pow((comments - 224.36),2) + pow((shares - 40.02),2) + pow((likes - 215.04),2) + pow((loves - 12.73),2) + pow((wows - 1.29),2) + pow((hahas - 0.70),2) + pow((sads - 0.24),2) + pow((angrys - 0.11),2));
    return calculated;
}
