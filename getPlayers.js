// Set all player value to 0 (there are x player with n player to out)
// if x < n -> update n to n - x
// random players who have second most value to find n - x players to not update their value
// else if x > n 
// random x players to find 

const stats = { totalMatch: 0 };
const players = [
	{ id: 1, name: "Chondan", value: 0 },
	{ id: 2, name: "Nut", value: 0 },
	{ id: 3, name: "Tonnam", value: 0 },
	{ id: 4, name: "Boss", value: 0 },
	{ id: 5, name: "Charlie", value: 0 },
	{ id: 6, name: "Phitak", value: 0 },
	{ id: 7, name: "Mew", value: 0 },
	{ id: 8, name: "Poom", value: 0 },
	{ id: 9, name: "Im", value: 0 },
	{ id: 10, name: "Taam", value: 0 },
];

const getRemovePlayers = (players, n) => {
	if (n > players.length) throw new Error('Out of index');

	const removePlayers = players.sort((a, b) => 0.5 - Math.random());
	return removePlayers.slice(0, n);
}

const getQualifyPlayers = (players, removePlayers) => {
		const qualifyPlayers = players.filter(player => !removePlayers.includes(player));
		qualifyPlayers.forEach(player => player.value += 1);
		return qualifyPlayers;
}

const getRemainPlayers = (players, removePlayers) => {
	const remainPlayers = players.filter(player => !removePlayers.includes(player));
	const sortedRemainPlayers = remainPlayers.sort((a, b) => b.value - a.value);
	return sortedRemainPlayers;
}

const getPlayers = (players, toRemove) => {

	const candidate = players.filter(player => {
		const max = players.sort((a, b) => b.value - a.value)[0].value;
		return player.value == max;
	});
	const remain = getRemainPlayers(players, candidate);

	if (candidate.length > toRemove) {

		const removePlayers = getRemovePlayers(candidate, toRemove);
		return getQualifyPlayers(players, removePlayers);

	} else if (candidate.length < toRemove) {

		const removePlayers = candidate.concat(getRemovePlayers(remain, toRemove - candidate.length));
		return getQualifyPlayers(players, removePlayers);

	} else {
		return getQualifyPlayers(players, candidate);
	}

}

const simulate = () => {

	const x = [];
	Array(10).fill(null).forEach(() => {
		x.push(getPlayers(players, 3));
	});
	console.log(x);
}

simulate();
console.log(players);