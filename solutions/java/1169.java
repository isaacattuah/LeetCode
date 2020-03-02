class Solution {
  public List<String> invalidTransactions(String[] transactions) {
    Map<String, List<String[]>> map = new HashMap<>();
    Set<String> ans = new HashSet<>();

    for (String transaction : transactions) {
      String[] token = transaction.split(",");
      if (Integer.valueOf(token[2]) > 1000)
        ans.add(transaction);
      if (map.containsKey(token[0]))
        for (String[] val : map.get(token[0]))
          if (Math.abs(Integer.valueOf(val[1]) - Integer.valueOf(token[1])) <= 60 && !val[3].equals(token[3])) {
            ans.add(transaction);
            ans.add(val[0] + "," + val[1] + "," + val[2] + "," + val[3]);
          }
      List<String[]> list = map.getOrDefault(token[0], new ArrayList<>());
      list.add(new String[] { token[0], token[1], token[2], token[3] });
      map.put(token[0], list);
    }

    return new ArrayList<>(ans);
  }
}