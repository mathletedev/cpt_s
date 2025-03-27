{ pkgs ? import <nixpkgs> { } }:

let
  texlive = pkgs.texliveBasic.withPackages (ps: with ps; [
    braket
    cleveref
    enumitem
    fancyvrb
    hyperref
    minted
    pgf
    pkgs.python3Packages.pygments
    upquote
  ]);
in
pkgs.mkShell {
  buildInputs = with pkgs; [
    tex-fmt
    texlab
    texlive
  ];
}
