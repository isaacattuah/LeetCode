class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> idToEmployee;

    for (Employee* employee : employees) idToEmployee[employee->id] = employee;

    return dfs(idToEmployee, id);
  }

 private:
  int dfs(unordered_map<int, Employee*>& idToEmployee, int id) {
    int subordinatesImportance = 0;

    for (int subordinate : idToEmployee[id]->subordinates)
      subordinatesImportance += dfs(idToEmployee, subordinate);

    return idToEmployee[id]->importance + subordinatesImportance;
  }
};