function newline() {
  console.log("\n");
}

function print(data) {
  if (data === 1) process.stdout.write("* ");

  if (data === 0) process.stdout.write("# ");
}

let board_size = 10;

for (let i = 1; i <= board_size; i++) {
  for (let j = 1; j <= board_size; j++) {
    if (i % 2 != 0) {
      if (i % 2 != 0 && j % 2 != 0) print(1);

      if (i % 2 != 0 && j % 2 == 0) print(0);
    }

    if (i % 2 == 0) {
      if (i % 2 == 0 && j % 2 == 0) print(1);

      if (i % 2 == 0 && j % 2 != 0) print(0);
    }
  }

  newline();
}
