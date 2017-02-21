using UnityEngine;
using System.Collections;

public class enemymovement : MonoBehaviour {

    // Use this for initialization

    Rigidbody2D boarrigidbody;
    Animator boaranimator;
    Transform karakterposition;
    float boarspeed = 0.3f;




    void Start () {

        boarrigidbody = GetComponent<Rigidbody2D>();
        boaranimator = GetComponent<Animator>();
        karakterposition = GameObject.Find("player").GetComponent<karakter>().transform;    
    }
	
	
	void Update ()
    {
             
    }


    void OnTriggerEnter2D(Collider2D col)
    {
        flip();
    }


      void OnTriggerStay2D(Collider2D col)
    {
        
        if (col.gameObject.tag == "Player" && karakterposition.transform.position.x < transform.position.x)
        {
            boaranimator.SetBool("charging", true);
            boarrigidbody.AddForce(new Vector2(-boarspeed, 0),ForceMode2D.Impulse);
        }
        if (col.gameObject.tag == "Player" && karakterposition.transform.position.x > transform.position.x)
        {
            boaranimator.SetBool("charging", true);
            boarrigidbody.AddForce(new Vector2(boarspeed, 0),ForceMode2D.Impulse);
        }
 
    }

    void OnTriggerExit2D(Collider2D col)
    {
        if (col.gameObject.tag == "Player" && karakterposition.transform.position.x < transform.position.x)
        {
            boarrigidbody.AddForce(new Vector2(-0, 0));
            boaranimator.SetBool("charging", false);
        }
        if (col.gameObject.tag == "Player" && karakterposition.transform.position.x > transform.position.x)
        {
            boarrigidbody.AddForce(new Vector2(0, 0));
            boaranimator.SetBool("charging", false);
        }

    }

    void flip()
    {
        if(karakterposition.transform.position.x<transform.position.x)
        {
            transform.localScale = new Vector2(3, 3);
        }
        if (karakterposition.transform.position.x > transform.position.x)
        {
            transform.localScale = new Vector2(-3, 3);
        }
    }



}
