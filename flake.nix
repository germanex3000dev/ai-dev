{
  description = "Basic C++ Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux"; # swap to "aarch64-darwin" if you're on apple silicon, bro!
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          # Build tools & Compilers
          gcc
          cmake
          ninja
          
          # Debugging & Tooling
          gdb
          clang-tools # includes clangd for LSP, clang-format, etc.
        ];

        shellHook = ''
          echo "Compiler: $(gcc --version | head -n 1)"
        '';
      };
    };
}

