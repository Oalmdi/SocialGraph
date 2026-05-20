#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User;

struct FollowNode {
    struct User *user;
    struct FollowNode *next;
};

struct User {
    int user_id;
    char user_name[50];
    int user_age;

    struct FollowNode *following;
    struct FollowNode *followers;

    struct User *next;
};

struct User *createUser(int id, char name[], int age) {
    struct User *newUser = malloc(sizeof(struct User));

    newUser->user_id = id;
    strcpy(newUser->user_name, name);
    newUser->user_age = age;

    newUser->following = NULL;
    newUser->followers = NULL;
    newUser->next = NULL;

    return newUser;
}

struct FollowNode *createFollowNode(struct User *user) {
    struct FollowNode *newNode = malloc(sizeof(struct FollowNode));

    newNode->user = user;
    newNode->next = NULL;

    return newNode;
}

void addUser(struct User **head, struct User *newUser) {
    if (*head == NULL) {
        *head = newUser;
        return;
    }

    struct User *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newUser;
}

void followUser(struct User *follower, struct User *followed) {
    struct FollowNode *newFollowing = createFollowNode(followed);
    newFollowing->next = follower->following;
    follower->following = newFollowing;

    struct FollowNode *newFollower = createFollowNode(follower);
    newFollower->next = followed->followers;
    followed->followers = newFollower;
}

void printFollowing(struct User *user) {
    printf("\n%s follows:\n", user->user_name);

    struct FollowNode *temp = user->following;

    if (temp == NULL) {
        printf("No one\n");
        return;
    }

    while (temp != NULL) {
        printf("- %s\n", temp->user->user_name);
        temp = temp->next;
    }
}

void printFollowers(struct User *user) {
    printf("\n%s followers:\n", user->user_name);

    struct FollowNode *temp = user->followers;

    if (temp == NULL) {
        printf("No followers\n");
        return;
    }

    while (temp != NULL) {
        printf("- %s\n", temp->user->user_name);
        temp = temp->next;
    }
}

void printAllUsers(struct User *head) {
    printf("\nAll Users:\n");

    struct User *temp = head;

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d\n",
               temp->user_id,
               temp->user_name,
               temp->user_age);

        temp = temp->next;
    }
}

int main() {
    struct User *head = NULL;

    struct User *Ahmed = createUser(1, "Ahmed", 20);
    struct User *Khaled = createUser(2, "Khaled", 25);
    struct User *Ali = createUser(3, "Ali", 22);
    struct User *Mohammed = createUser(4, "Mohammed", 23);

    addUser(&head, Ahmed);
    addUser(&head, Khaled);
    addUser(&head, Ali);
    addUser(&head, Mohammed);

    followUser(Ahmed, Khaled);
    followUser(Ahmed, Ali);
    followUser(Khaled, Mohammed);
    followUser(Ali, Mohammed);

    printAllUsers(head);

    printFollowing(Ahmed);
    printFollowers(Ahmed);

    printFollowing(Khaled);
    printFollowers(Khaled);

    printFollowing(Mohammed);
    printFollowers(Mohammed);

    return 0;
}