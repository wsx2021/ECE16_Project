
/*
 * check if score is a top score. 
 */
void update_topscore(int score) {
  if (score > top1) {
    top3 = top2;
    top2 = top1;
    top1 = score;
  }
  else if (score > top2) {
    top3 = top2;
    top2 = score;
  }
  else if (score > top3) {
    top3 = score; 
  }
}


/* 
 *  Was thing have a function for all new game tasks such as topscore, reset life number
 */
//void new_game() {
//  
//}
