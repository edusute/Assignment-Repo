## Repo-level instructions for AI coding agents

This repository is a collection of course materials (Markdown lessons and project templates) focused on introductory AI concepts using Python and SQLite. Your edits should be precise, preserve teaching examples, and follow the conventions used in the lessons.

Keep the guidance below short and actionable — use examples from the repository when possible.

### Big picture
- Primary artifacts are Markdown lessons (root .md files) that teach concepts and include runnable Python snippets (examples: `ai02bLessonDecisionTreesInPython.md`, `ai03bSQLiteBasicsWithPython.md`, `ai03dTeamProjectMovieDbReccomendations.md`).
- Common pattern across lessons: Query → Decide → Store (see `ai03cDatabases&DecisionTrees.md`). Decision trees are implemented with nested if/elif/else; database code uses Python's builtin `sqlite3`.

### What to change and what to preserve
- Preserve pedagogical structure: learning objectives, step-by-step examples, and sample runs. Students rely on exact code fences and sample output.
- Keep emoji, diagrams, and code fences intact when they add clarity. Do not convert inline sample outputs into comments or remove user-facing examples.
- When extracting code into .py files, keep code behavior identical to the snippet in the lesson (same prompts, same outputs).

### Project-specific conventions and idioms
- SQLite usage: connect with `sqlite3.connect('<filename>.db')`, use `cursor.execute()` with `?` placeholders for parameters, call `connection.commit()` then `connection.close()`.
  - Example pattern: `connection = sqlite3.connect('movies.db')` → `cursor = connection.cursor()` → `cursor.execute(...)` → `connection.commit()` → `connection.close()` (see `ai03bSQLiteBasicsWithPython.md`).
- Data types used in schema examples: INTEGER, TEXT, REAL. Tables typically include an `id` column and human-readable columns like `title`, `genre`, `rating`, `year`.
- Input normalization: lessons recommend `.lower()` for text input and `.isdigit()` checks before casting; mirror this when implementing user-facing scripts (`ai02bLessonDecisionTreesInPython.md`).
- Function/structure guidance: lessons favor small helper functions (e.g., `setup_database()`, `add_sample_data()`, `recommend_movie()`). Follow that pattern when creating utilities.

### Data flow / integration points
- Decision logic frequently reads from SQLite, makes decisions, and writes results back (the canonical pattern: Query → Decide → Store). See `ai03cDatabases&DecisionTrees.md` and `ai03dTeamProjectMovieDbReccomendations.md` for examples.
- Typical filenames seen in lessons: `movies.db`, `movie_database.db`, `movie_recommender.db`, `study_tracker.db`. If you add examples or scripts, use clear, unique filenames or keep DB files out of source control and add them to .gitignore.

### Running and testing code (developer workflow)
- There is no build system in this repo — Python snippet execution is the normal workflow. Use the system Python 3 interpreter: `python3 script.py` on macOS (bash shell).
- If you create runnable scripts, add a short README or a one-line header in the file explaining how to run it (e.g., `python3 example_recommender.py`).

### Editing patterns for agents
- When converting lesson examples into standalone scripts, preserve the exact prompts and sample outputs used in the lesson so students see consistent behavior.
- When refactoring, keep behavior the same and add small helper functions. Add `if __name__ == "__main__": main()` wrappers to runnable examples.
- Use parameterized SQL (`?`) — prefer this over string interpolation to avoid promoting insecure patterns.

### Files and places to reference in edits
- Lesson entry points: `ai01LessonIntro.md`, `ai02aLessonDecisionTrees.md`, `ai02bLessonDecisionTreesInPython.md`, `ai03bSQLiteBasicsWithPython.md`, `ai03cDatabases&DecisionTrees.md`, `ai03dTeamProjectMovieDbReccomendations.md`.
- Templates & sample functions: `ai03dTeamProjectMovieDbReccomendations.md` contains `setup_database()`, `add_sample_data()`, `recommend_movie()` which are canonical examples to reuse.

### Safety & scope
- Do not invent build steps, CI config, or package manifests. If adding dependencies (e.g., scikit-learn) mention them in a README and propose `requirements.txt` but don't add one without confirmation.
- Avoid adding binary DB files under source control. If you need to add example DBs, put instructions to generate them instead.

### Examples for quick reference (short snippets to mirror)
- Connect & commit pattern:
```
connection = sqlite3.connect('movies.db')
cursor = connection.cursor()
cursor.execute('CREATE TABLE IF NOT EXISTS movies (id INTEGER, title TEXT, rating REAL)')
connection.commit()
connection.close()
```
- Query → Decide → Store pattern (pseudocode):
```
# Query user prefs
cursor.execute('SELECT favorite_genre FROM users WHERE id = ?', (user_id,))
pref = cursor.fetchone()
# Decide
if pref == 'Sci-Fi': ...
# Store recommendation
cursor.execute('INSERT INTO recommendations (user_id, movie_id, recommendation_date) VALUES (?, ?, ?)', (...))
connection.commit()
```

---
If anything below is unclear or you want me to include extra run instructions or a sample script derived from a lesson, tell me which lesson to convert and I will add it. 
