const fs = require('fs');

// Read the file 'out' synchronously and split by lines
const lines = fs.readFileSync('out', 'utf-8').trim().split('\n');

const mealCount = {};

lines.forEach(line => {
	const parts = line.trim().split(" ");
	if (parts.length < 3) return;

	const id = parts[1];
	const action = parts.slice(2).join(" ");

	if (action === "is eating") {
		if (!mealCount[id]) mealCount[id] = 0;
		mealCount[id]++;
	}
});

// Print how much each philosopher ate
const ids = Object.keys(mealCount).sort((a, b) => Number(a) - Number(b));
ids.forEach(id => {
	console.log(`Philosopher ${id} ate ${mealCount[id]} time(s)`);
});

// Check if all philosophers ate >= 100 meals
const allAteEnough = ids.length > 0 && ids.every(id => mealCount[id] >= 100);

if (allAteEnough) {
	console.log("✅ All philosophers ate 100 meals or more.");
} else {
	console.log("❌ Not all philosophers ate 100 meals.");
}
