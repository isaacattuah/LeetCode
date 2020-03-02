class Solution {
  public String[] spellchecker(String[] wordlist, String[] queries) {
    List<String> ans = new ArrayList<>();

    for (final String word : wordlist) {
      dict.putIfAbsent(word, word);
      dict.putIfAbsent(lowerKey(word), word);
      dict.putIfAbsent(vowelKey(word), word);
    }

    for (final String query : queries) {
      if (dict.containsKey(query))
        ans.add(dict.get(query));
      else if (dict.containsKey(lowerKey(query)))
        ans.add(dict.get(lowerKey(query)));
      else if (dict.containsKey(vowelKey(query)))
        ans.add(dict.get(vowelKey(query)));
      else
        ans.add("");
    }

    return ans.toArray(new String[0]);
  }

  private Map<String, String> dict = new HashMap<>();

  private String lowerKey(final String word) {
    String s = "$";
    for (char c : word.toCharArray())
      s += Character.toLowerCase(c);
    return s;
  }

  private String vowelKey(final String word) {
    String s = "";
    for (char c : word.toCharArray())
      s += isVowel(c) ? '*' : Character.toLowerCase(c);
    return s;
  }

  private boolean isVowel(char c) {
    c = Character.toLowerCase(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
}