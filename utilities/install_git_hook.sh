#!/bin/sh

if ! test -d .git; then
    echo "Execute scripts/install-git-hooks in the top-level directory."
    exit 1
fi

ln -sf ../../utilities/pre-commit.hook .git/hooks/pre-commit || exit 1
chmod +x .git/hooks/pre-commit

# ln -sf ../../scripts/commit-msg.hook .git/hooks/commit-msg || exit 1
# chmod +x .git/hooks/commit-msg

touch .git/hooks/applied || exit 1

echo
echo "Git commit hooks are installed successfully."
