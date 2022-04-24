vector<int> gradingStudents(vector<int> grades) {
    for(int & grade: grades) {
        if ( grade < 38 ) continue;
        int delta = 5 - (grade % 5);
        if (delta < 3) grade += delta;
    }
    return grades;
}
