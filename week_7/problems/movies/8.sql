SELECT name FROM people WHERE id IN (SELECT person_id FROM movies JOIN stars ON stars.movie_id = movies.id WHERE title = 'Toy Story');