const input = await Deno.readTextFile("./input.txt");
const lines = input.split("\n");

// Improved regex for more flexible matching
const mulRegex = /mul\((\d+),(\d+)\)/;
const toggleOnRegex = /do\(\)/;
const toggleOffRegex = /don't\(\)/;

let total = 0;
let gate = true; // Gate is initially true (calculations are enabled)

// Iterate over each line
for (let line of lines) {
  console.log(`Processing line: ${line}`);

  // Split the line into tokens that we'll process sequentially
  const tokens = line.match(/mul\(\d+,\d+\)|do\(\)|don't\(\)/g) || [];

  for (const token of tokens) {
    // Check for toggle off
    if (token === "don't()") {
      gate = false;
      console.log("Gate toggled OFF.");
      continue;
    }

    // Check for toggle on
    if (token === "do()") {
      gate = true;
      console.log("Gate toggled ON.");
      continue;
    }

    // Process mul(x,x) if the gate is on
    if (gate) {
      const match = token.match(mulRegex);
      if (match) {
        const result = parseInt(match[1]) * parseInt(match[2]);
        total += result;
        console.log(`Calculated mul(${match[1]}, ${match[2]}) = ${result}`);
      }
    }
  }

  console.log(`Processed line: ${line}`);
}

console.log(`Total: ${total}`);
