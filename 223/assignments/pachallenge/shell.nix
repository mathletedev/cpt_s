{ pkgs ? import <nixpkgs> { }, pkgsUnstable ? import <nixpkgs-unstable> { } }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    pkgsUnstable.boost
  ];
}
