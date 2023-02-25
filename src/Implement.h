#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double jaroWinklerDistance(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  int matchDistance = max(len1, len2) / 2 - 1;
  vector<bool> s1Matches(len1, 0);
  vector<bool> s2Matches(len2, 0);
  int matches = 0;
  for (int i = 0; i < len1; i++) {
    int start = max(0, i - matchDistance);
    int end = min(i + matchDistance + 1, len2);
    for (int j = start; j < end; j++) {
      if (!s2Matches[j] && s1[i] == s2[j]) {
        s1Matches[i] = true;
        s2Matches[j] = true;
        matches++;
        break;
      }
    }
  }

  if (matches == 0) {
    return 0.0;
  }

  int transpositions = 0;
  int k = 0;
  for (int i = 0; i < len1; i++) {
    if (s1Matches[i]) {
      while (!s2Matches[k]) {
        k++;
      }
      if (s1[i] != s2[k]) {
        transpositions++;
      }
      k++;
    }
  }
  transpositions /= 2;

  double jaroDistance = (double)matches / len1 + (double)matches / len2 +
                        (double)(matches - transpositions) / matches;
  if (jaroDistance < 0.7) {
    return jaroDistance;
  }

  int prefixLength = 0;
  while (prefixLength < 4 && prefixLength < min(len1, len2) &&
         s1[prefixLength] == s2[prefixLength]) {
    prefixLength++;
  }

  double scalingFactor = 0.1;
  return jaroDistance + prefixLength * scalingFactor * (1 - jaroDistance);
}

void findMostAppropriateKeyword(vector<string> keywords, string query) {
  string mostAppropriateKeyword;
  double maxScore = 0.0;
  int count = 1;
  cout << "There are Similar Question\n";
  for (auto keyword : keywords) {
    double score = jaroWinklerDistance(keyword, query);

    if (score > maxScore) {
      maxScore = score;
      cout << count++ << ": " << keyword << endl;
    }
  }
}
std::vector<std::string> commonWords = {
    "a",           "of",           "able",      "about",
    "above",       "abroad",       "according", "accordingly",
    "across",      "actually",     "adj",       "after",
    "afterwards",  "again",        "against",   "ago",
    "ahead",       "ain't",        "all",       "allow",
    "allows",      "almost",       "alone",     "along",
    "alongside",   "already",      "also",      "although",
    "always",      "am",           "amid",      "amidst",
    "among",       "amongst",      "an",        "and",
    "another",     "any",          "anybody",   "anyhow",
    "anyone",      "anything",     "anyway",    "anyways",
    "anywhere",    "apart",        "appear",    "appreciate",
    "appropriate", "are",          "aren't",    "around",
    "as",          "a's",          "aside",     "ask",
    "asking",      "associated",   "at",        "available",
    "away",        "awfully",      "b",         "back",
    "backward",    "algorithm",    "array",     "class",
    "compile",     "constructor",  "debug",     "destructor",
    "exception",   "function",     "header",    "inheritance",
    "library",     "linker",       "loop",      "method",
    "namespace",   "object",       "operator",  "overloading",
    "pointer",     "polymorphism", "recursion", "stack",
    "template",    "variable",     "code",      "give",
    "me",          "program",      "the",       "coding",
    "question"

};
string removeWordsFromQuery(string &query, vector<string> wordsToRemove) {
  vector<string> words;
  istringstream iss(query);
  copy(istream_iterator<string>(iss), istream_iterator<string>(),
       back_inserter(words));

  // Remove the specified words from the list of words
  for (auto it = words.begin(); it != words.end();) {
    if (find(wordsToRemove.begin(), wordsToRemove.end(), *it) !=
        wordsToRemove.end()) {
      it = words.erase(it);
    } else {
      ++it;
    }
  }

  // Reconstruct the query string from the list of words
  query.clear();
  for (size_t i = 0; i < words.size(); ++i) {
    if (i > 0) {
      query += ' ';
    }
    query += words[i];
  }
  return query;
}