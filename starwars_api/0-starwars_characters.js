#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Failed to get movie. Status code: ${response.statusCode}`);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  const printCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, data) => {
      if (!err && res.statusCode === 200) {
        const character = JSON.parse(data);
        console.log(character.name);
        printCharacter(index + 1);
      } else {
        console.error('Error fetching character:', characters[index]);
      }
    });
  };

  printCharacter(0);
});
