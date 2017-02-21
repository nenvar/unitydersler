using UnityEngine;
using System.Collections;

public class collisiontrigger : MonoBehaviour {

    // Use this for initialization

    public BoxCollider2D playercollider;
    public BoxCollider2D platformcollider1;
    public BoxCollider2D platformcollider2;

	void Start()
    {
        playercollider = GameObject.Find("karakter").GetComponent<BoxCollider2D>();
        Physics2D.IgnoreCollision(platformcollider1, platformcollider2,true);
    }
	
	
    void OnTriggerEnter2D(Collider2D col)
    {
        if(col.gameObject.name == "karakter")
        {
            Physics2D.IgnoreCollision(playercollider, platformcollider1,true);
        }
    }

    void OnTriggerExit2D(Collider2D col)
    {
        if (col.gameObject.name == "karakter")
        {
            Physics2D.IgnoreCollision(playercollider, platformcollider1,false);
        }
    }
}
