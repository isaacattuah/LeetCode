class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<>();

    for (final String str : strs) {
      char[] charArray = str.toCharArray();
      Arrays.sort(charArray);
      String s = String.valueOf(charArray);
      map.putIfAbsent(s, new ArrayList<>());
      map.get(s).add(str);
    }

    return new ArrayList<>(map.values());
  }
}