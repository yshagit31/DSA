// 2115. Find All Possible Recipes from Given Supplies

// You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

// You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

// Return a list of all the recipes that you can create. You may return the answer in any order.

// Note that two recipes may contain each other in their ingredients.

// Example 1:

// Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
// Output: ["bread"]
// Explanation:
// We can create "bread" since we have the ingredients "yeast" and "flour".
// Example 2:

// Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
// Output: ["bread","sandwich"]
// Explanation:
// We can create "bread" since we have the ingredients "yeast" and "flour".
// We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
// Example 3:

// Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
// Output: ["bread","sandwich","burger"]
// Explanation:
// We can create "bread" since we have the ingredients "yeast" and "flour".
// We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
// We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

// Constraints:

// n == recipes.length == ingredients.length
// 1 <= n <= 100
// 1 <= ingredients[i].length, supplies.length <= 100
// 1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
// recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
// All the values of recipes and supplies combined are unique.
// Each ingredients[i] does not contain any duplicate values.

#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:
        vector<string> findAllRecipes(vector<string>& recipes, 
        vector<vector<string>>& ingredients, vector<string>& supplies) {
           unordered_map<string,vector<string>>adj;
           unordered_map<string,int>indegree;
    
           unordered_set<string>supply(supplies.begin(),supplies.end());
    
            vector<string> ans;
    
            for(int i=0;i<recipes.size();i++)
            {
                indegree[recipes[i]]=0;
                for(auto it:ingredients[i])
                {
                    if(supply.count(it)==0)
                    {
                        adj[it].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }
            }
    
            queue<string> q;
            for(auto & [recipe,indeg]:indegree)
            {
                if(indeg==0)
                {
                    q.push(recipe);
                }
            }
    
           while(!q.empty())
           {
            string curr_recipe=q.front();
            q.pop();
            ans.push_back(curr_recipe);
    
            for(string & next_recipe : adj[curr_recipe])
            {
                indegree[next_recipe]--;
                if(indegree[next_recipe]==0)
                    q.push(next_recipe);
            }
           }
    
             return ans;
        }
    };